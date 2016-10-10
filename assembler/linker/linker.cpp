#include <vector>
#include <string>

#include <cstddef>

#include <STDExtras.hpp>
#include <STLExtras.hpp>
#include <os-specific.hpp>
#include <convert.hpp>

#include "../lexer/lexer.hpp"
#include "linker.hpp"

LLCCEP_ASM::linker::linker():
	_variablesLabels(),
	_released()
{ }

LLCCEP_ASM::linker::~linker()
{ }

bool LLCCEP_ASM::linker::hasDeclaration(::std::vector<lexem> lex) const
{
	return hasVariableModification(lex) || hasLabelDeclaration(lex);
}

void LLCCEP_ASM::linker::modifyVariablesTable(::std::vector<lexem> lex)
{
	if (!hasVariableModification(lex))
		return;

	auto isVariableDeclaration = [lex] {
		return lex[0].type == LLCCEP_ASM::LEX_T_VAR;
	};

	auto isVariableDeletion = [lex] {
		return lex[0].type == LLCCEP_ASM::LEX_T_RELEASE;
	};

	auto lastVariable = [this] {
		for (auto i = _variablesLabels.begin(); i < _variablesLabels.end(); i++)
			if (!i->label)
				return i;

		return _variablesLabels.end();
	};

	auto createVariable = [this, lastVariable, isVariableDeclaration, lex] {
		if (!isVariableDeclaration())
			return;

		for (const auto &i: _variablesLabels) {
			if (i.lexemData.val == lex[1].val) {
				linkerIssue(lex[1],
					    "'%s' was already "
					    "declared in '%s' file on line " size_t_pf,
					    lex[1].val.c_str(), 
					    i.lexemData.pos.file.c_str(),
					    i.lexemData.pos.line);
			}
		}

		saveData newVariable{lex[1], 0, false};
		if (_released.size()) {
			newVariable.pos = *(_released.end() - 1);
			_released.pop_back();
		} else if (lastVariable() < _variablesLabels.end()) {
			newVariable.pos = lastVariable()->pos + 1;
		} else {
			newVariable.pos = 32;
		}

		_variablesLabels.push_back(newVariable);
	};

	auto deleteVariable = [this, isVariableDeletion, lex] {
		if (!isVariableDeletion())
			return;

		size_t oldSize = _variablesLabels.size();
		for (auto i = _variablesLabels.begin(); 
		     i < _variablesLabels.end(); i++) {
			if (i->lexemData.val == lex[1].val) {
				_released.push_back(i->pos);
				_variablesLabels.erase(i);
				break;
			}
		}

		if (_variablesLabels.size() == oldSize) {
			linkerIssue(lex[1],
				    "'%s' was not declared yet",
				    lex[1].val.c_str());
		}
	};

	if (isVariableDeclaration())
		createVariable();
	else if (isVariableDeletion())
		deleteVariable();
}

void LLCCEP_ASM::linker::buildLabelsAssociativeTable(::std::vector<lexem> lex,
                                                     size_t iteration)
{
	if (!hasLabelDeclaration(lex))
		return;

	auto buildLabelData = [lex, iteration] {
		return saveData{lex[0], iteration, true};
	};

	saveData newLabel = buildLabelData();

	for (const auto &i: _variablesLabels) {
		if (i.lexemData.val == newLabel.lexemData.val) {
			linkerIssue(newLabel.lexemData, 
				    "'%s' label was already declared at " 
				    size_t_pf " line of '%s' file.",
				    i.lexemData.val.c_str(), i.lexemData.pos.line,
				    i.lexemData.pos.file.c_str());
		}
	}

	_variablesLabels.push_back(newLabel);
}

void LLCCEP_ASM::linker::substituteWithAddresses(::std::vector<lexem> &lexems)
{
	auto substituteName = [this](LLCCEP_ASM::lexem &lexemData) {
		for (auto &i: _variablesLabels) {
			if (i.lexemData.val == lexemData.val) {
				if (i.label)
					lexemData.type = LEX_T_VAL;
			       	else
					lexemData.type = LEX_T_MEM;

				lexemData.val = to_string(i.pos);
				return;
			}
		}

		linkerIssue(lexemData, 
			    "'%s' was not declared in this scope!",
			    lexemData.val.c_str());
	};

	bool instruction = true;
	for (auto &i: lexems) {
		if (instruction) {
			instruction = false;
			continue;
		}

		if (i.type == LLCCEP_ASM::LEX_T_NAME)
			substituteName(i);
	}
}

size_t LLCCEP_ASM::linker::getMainAddress() const
{
	for (const auto &i: _variablesLabels) {
		if (i.lexemData.val == "_main") {
			if (!i.label)
				linkerIssue(i.lexemData, "_main is not label!");
			
			return i.pos;
		}
	}

	linkerIssue(LLCCEP_ASM::lexem{}, "_main was not declared in this scope");
	return 0;
}

void LLCCEP_ASM::linker::linkerIssue(LLCCEP_ASM::lexem issuedLabel, const char *fmt, ...) const
{
	va_list list;
	va_start(list, fmt);

	char res[4096] = "";
	vsprintf(res, (issuedLabel.pos.file + ::std::string(":") + 
		       to_string(issuedLabel.pos.line) + ::std::string(":\n") +
		       ::std::string(fmt)).c_str(), list);

	va_end(list);

	throw RUNTIME_EXCEPTION(CONSTRUCT_MSG("%s", res))
}

bool LLCCEP_ASM::linker::hasLabelDeclaration(::std::vector<LLCCEP_ASM::lexem> lex) const
{
	if (lex.size() >= 2 && lex[0].type == LLCCEP_ASM::LEX_T_NAME &&
	    lex[1].type == LLCCEP_ASM::LEX_T_COLON) {
		if (lex.size() > 2) {
			linkerIssue(lex[0],
				    "Junk lexems after '%s' label declaration",
				    lex[0].val.c_str());
		}

		return true;
	}

	return false;
}

bool LLCCEP_ASM::linker::hasVariableModification(::std::vector<LLCCEP_ASM::lexem> lex) const
{
	if (lex.size() && (lex[0].type == LLCCEP_ASM::LEX_T_VAR ||
	                   lex[0].type == LLCCEP_ASM::LEX_T_RELEASE)) {
		if (lex.size() < 2 || lex[1].type != LLCCEP_ASM::LEX_T_NAME) {
			linkerIssue(lex[0], 
				    "Excepted variable name after '%s'",
				    (lex[0].type == LLCCEP_ASM::LEX_T_VAR)?
				    ("var"):
				    ("release"));
		} else if (lex.size() > 2) {
			linkerIssue(lex[0],
				    "Junk lexems after '%s' variable %s",
				    lex[1].val.c_str(),
				    (lex[0].type == LLCCEP_ASM::LEX_T_VAR)?
				    ("declaration"):
				    ("deletion"));
		}

		return true;
	}

	return false;
}


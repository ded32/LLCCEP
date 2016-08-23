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

bool LLCCEP_ASM::linker::modifyVariablesTable(::std::vector<lexem> lex)
{
	auto isVariableDeclaration = [lex] {
		return (lex.size() >= 2 &&
		        lex[0].type == LEX_T_VAR && 
			lex[1].type == LEX_T_NAME);
	};

	auto isVariableDeletion = [lex] {
		return (lex.size() >= 2 &&
			lex[0].type == LEX_T_RELEASE &&
			lex[1].type == LEX_T_NAME);
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
					    "declared in '%s' file on line "
					    size_t_pf,
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

	if (isVariableDeclaration()) {
		if (lex.size() > 2) {
			linkerIssue(lex[1], 
				    "Junk expressions after '%s' declaration",
				    lex[1].val.c_str());
		}

		createVariable();
		return true;
	} else if (isVariableDeletion()) {
		if (lex.size() < 2) {
		       linkerIssue(lex[1],
				   "Junk expressions after '%s' deletion",
				   lex[1].val.c_str());
		}

		deleteVariable();
		return true;
	}

	return false;
}

bool LLCCEP_ASM::linker::buildLabelsAssociativeTable(::std::vector<lexem> lex,
                                                     size_t iteration)
{
	auto isLabel = [lex] {
		return ((lex.size() >= 2)?
			(lex[0].type == LEX_T_NAME && lex[1].type == LEX_T_COLON):
			(false));
	};

	auto buildLabelData = [this, isLabel, lex, iteration] {
		if (!isLabel())
			return saveData{};

		if (lex.size() > 2) {
			linkerIssue(lex[0], 0, 
				    "Junk expressions after '%s' declaration",
				    lex[0].val.c_str());
		}

		return saveData{lex[0], iteration, true};
	};

	saveData newLabel = buildLabelData();
	if (!newLabel.lexemData.val.length())
		return false;

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
	return true;
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

void LLCCEP_ASM::linker::linkerIssue(LLCCEP_ASM::lexem issuedLabel, const char *fmt, ...)
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

#include <string>
#include <map>
#include <vector>
#include <cctype>
#include <cstddef>
#include <cstdarg>
#include <iostream>

#include <convert.hpp>
#include <STDExtras.hpp>
#include <os-specific.hpp>

#include "./../common/def/def_inst.hpp"
#include "./../common/def/def_cond.hpp"

#include "lexer.hpp"

#define LEXER_OK DEFAULT_CHECK_BLOCK(true, this, ok())
#define LEXER_NOT_OK DEFAULT_CHECK_BLOCK(false, this, ok())

LLCCEP_ASM::lexer::lexer():
	_path(),
	_line(1),
	_in(0),
	_started(false)
{ }

LLCCEP_ASM::lexer::~lexer()
{ }

void LLCCEP_ASM::lexer::setProcessingPath(::std::string path)
{
	LEXER_NOT_OK
	
	_path = path;
}

void LLCCEP_ASM::lexer::setProcessingFile(::std::istream *in)
{
	LEXER_NOT_OK
	
	_in = in;
	_started = true;
	
	LEXER_OK
}

void LLCCEP_ASM::lexer::getNextLine(::std::vector<LLCCEP_ASM::lexem> &lex)
{
	LEXER_OK
	
	auto nameApproached = [](char c, bool first = true) {
		return isalpha(c) || c == '_' || ((first)?(0):(isdigit(c)));
	};
	
	auto toLower = [](::std::string val) {
		::std::string res;
		
		for (size_t i = 0; i < val.length(); i++)
			res += tolower(val[i]);
		
		return res;
	};
	
	::std::string tmpString;
	::std::getline(*_in, tmpString);
	size_t i = 0, l = tmpString.length();
	
	while (i < l) {
		LLCCEP_ASM::lexem tmp{};
		tmp.pos.file = _path;
		tmp.pos.line = _line;

		if (nameApproached(tmpString[i])) {
			while (tmpString[i] && nameApproached(tmpString[i], false)) {
				tmp.val += tmpString[i];
				i++;
			}
			
			if (toLower(tmp.val) == "macro") {
				tmp.type = LLCCEP_ASM::LEX_T_MACRO;
			} else if (toLower(tmp.val) == "endmacro") {
				tmp.type = LLCCEP_ASM::LEX_T_ENDMACRO;
			} else if (toLower(tmp.val) == "var") {
				tmp.type = LLCCEP_ASM::LEX_T_VAR;
			} else if (toLower(tmp.val) == "release") {
				tmp.type = LLCCEP_ASM::LEX_T_RELEASE;
			} else if (LLCCEP_ASM::isInstruction(toLower(tmp.val)) > 0) {
				tmp.type = LLCCEP_ASM::LEX_T_NAME;
				tmp.val = toLower(tmp.val);
			} else {
				tmp.type = LLCCEP_ASM::LEX_T_NAME;
			}
		} else if (isdigit(tmpString[i]) || tmpString[i] == '.' || tmpString[i] == '-') {
			tmp.type = LLCCEP_ASM::LEX_T_VAL;

			while (tmpString[i] && (tmpString[i] == '-' ||
					        tmpString[i] == '.' ||	
						isdigit(tmpString[i]))) {
				tmp.val += tmpString[i];
				i++;
			}
		} else if (tmpString[i] == '"') {
			i++;

			tmp.type = LLCCEP_ASM::LEX_T_VAL;
			while (tmpString[i] && tmpString[i] != '"') {
				tmp.val += tmpString[i];
				i++;
			}

			if (tmpString[i] != '"')
				lexerIssue("Unclosed characted-instead-number");

			if (tmp.val.length() != 1)
				lexerIssue("Character-instead-number's length is not one character(inside quotes)");

			char c = tmp.val[0];
			tmp.val = to_string<int>(static_cast<int>(c));
			i++;
		} else if (tmpString[i] == '&') {
			tmp.type = LLCCEP_ASM::LEX_T_REG;
			i++;
			
			while (tmpString[i] && isdigit(tmpString[i])) {
				tmp.val += tmpString[i];
				i++;
			}
		} else if (tmpString[i] == '$') {
			tmp.type = LLCCEP_ASM::LEX_T_MEM;
			i++;
			
			while (tmpString[i] && isxdigit(tmpString[i])) {
				tmp.val += tmpString[i];
				i++;
			}
		} else if (tmpString[i] == '%') {
			tmp.type = LLCCEP_ASM::LEX_T_MACROARG;
			i++;
			
			while (tmpString[i] && isdigit(tmpString[i])) {
				tmp.val += tmpString[i];
				i++;
			}
		} else if (tmpString[i] == '@') {
			tmp.type = LLCCEP_ASM::LEX_T_COND;
			i++;
			
			while (tmpString[i] && nameApproached(tmpString[i], false)) {
				tmp.val += tmpString[i];
				i++;
			}
		} else if (tmpString[i] == ':') {
			tmp.type = LLCCEP_ASM::LEX_T_COLON;
			i++;
		} else if (tmpString[i] == '#' || tmpString[i] == ';') {
			break;
		} else if (tmpString[i] == ' ' || tmpString[i] == ',') {
			while (tmpString[i] == ' ' || tmpString[i] == ',')
				i++;
			
			continue;
		} else {
			lexerIssue("Forbidden character '%c'!", tmpString[i]);
		}
		
		lex.push_back(tmp);
	}

	_line++;
	
	LEXER_OK
}

bool LLCCEP_ASM::lexer::ok() const
{
	return _line && _in && _started;
}

void LLCCEP_ASM::lexer::lexerIssue(const char *fmt, ...)
{
	va_list list;
	va_start(list, fmt);
	
	char issueMessage[4096];
	vsprintf(issueMessage, fmt, list);
	va_end(list);
	
	throw RUNTIME_EXCEPTION(CONSTRUCT_MSG("%s:" size_t_pf ":\n%s", _path.c_str(), _line, issueMessage));
}

::std::string LLCCEP_ASM::getLexemTypename(LLCCEP_ASM::lex_t type)
{
	const ::std::map<LLCCEP_ASM::lex_t, ::std::string> typenames = {
		{LEX_T_REG,      "register"},
		{LEX_T_MEM,      "memory address"},
		{LEX_T_VAL,      "numeric value"},
		{LEX_T_COND,     "condition mnemonic"},
		{LEX_T_MACROARG, "macro argument"},
		{LEX_T_NAME,     "name"},
		{LEX_T_NO,       "none"},
		{LEX_T_COLON,    "colon"},
		{LEX_T_MACRO,    "'macro' string"},
		{LEX_T_ENDMACRO, "'endmacro' string"},
		{LEX_T_VAR,      "'var' string"},
		{LEX_T_RELEASE,  "'release' string"},
		{LEX_T_NEWLINE,  "new line"},
		{LEX_T_INVALID,  "invalid"}
	};
	
	if (typenames.find(type) == typenames.end()) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Overbounding while getting lexem's typename: no lexem type %d!",
			static_cast<int>(type)))
	}
	
	return typenames.at(type);
}

int64_t LLCCEP_ASM::isInstruction(::std::string str)
{
	for (int64_t i = 0; i < LLCCEP_ASM::INST_NUM; i++) {
		if (str == LLCCEP_ASM::INSTRUCTIONS[i].name)
			return i;
	}
	
	return -1;
}

int64_t LLCCEP_ASM::isCondition(::std::string str)
{
	return ((LLCCEP_ASM::CONDS.find(str) == LLCCEP_ASM::CONDS.end())?
		(-1):
		(LLCCEP_ASM::CONDS.at(str)));
}

bool LLCCEP_ASM::isNumSystem(char c)
{
	return (c == 'b') || (c == 'd') || (c == 'o') || (c == 'h');
}

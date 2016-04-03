#include <string>
#include <vector>
#include <cstdint>

#include "lexer.hpp"
#include "../errors/errors.hpp"

static const char OP_RESERVED[] = {
	'+', '-', '*', '/',
	'!', '>', '<', '='
};
#define OP_RESERVED_NUM 8

static const std::string MNEMONICS[] = {
	"extern", "def", "(", ")", "+", "-", 
	"*", "/" , "**", "+=", "-=", "*=", 
	"/=", "**=", "and", "or", "xor", "not",
	"==", "!=", ">=", "<=", ">", "<", "="
};
#define MNEMONICS_NUM 23

template<typename TYPE>
static int64_t is_in(const TYPE arr[], TYPE val, size_t max_sz)
{
	for (size_t i = 0; i < max_sz; i++)
		if (arr[i] == val)
			return i;

	return -1;
}

static int64_t is_op(char ch)
{
	return is_in(OP_RESERVED, ch, OP_RESERVED_NUM);
}

static bool is_id(std::string str)
{
	if (!isalpha(str[0]))
		return false;

	for (size_t i = 1; i < str.length(); i++)
		if (!isalnum(str[i]))
			return false;

	return true;
}

namespace LLCCEP_SiPy {
	void ToLexems(std::string str, std::vector<lexem> &lex, std::string file, size_t &line)
	{
		lexem tmp = {};
		size_t i = 0, l = str.length();

		while (i < l) {
			tmp.position.file = file;
			while (isspace(str[i])) {
				if (str[i] == '\n')
					line++;

				i++;
			}
			tmp.position.line = line;

			if (isalpha(str[i])) {
				std::string temp = "";
				while (isalnum(str[i])) {
					temp += str[i];
					i++;
				}

				int64_t pos = is_in(MNEMONICS, temp, MNEMONICS_NUM);
				if (pos == -1) {
					if (!is_id(temp)) {
						std::string msg = "Wrong characters' sequence: \"";
						msg += temp; msg += "\"!\n";
						throw SyntaxException(error_notify(file, line, msg));
					}

					tmp.type = LEX_T_ID;
					tmp.value = temp;
				} else {
					tmp.type = pos + 4;
					tmp.value = "";
				}
			} else if (is_op(str[i]) != -1) {
				std::string temp = "";
				while (is_op(str[i]) != -1) {
					temp += str[i];
					i++;
				}

				int64_t pos = is_in(MNEMONICS, temp, MNEMONICS_NUM);
				if (pos == -1) {
					std::string msg = "Unknown operator: \"";
					msg += temp; msg += "\"!\n";
					throw SyntaxException(error_notify(file, line, msg));
				} else {
					tmp.type = pos + 4;
					tmp.value = "";
				}
			} else if (isdigit(str[i]) || str[i] == '.') {
				std::string temp = "";
				while (isdigit(str[i]) || str[i] == '.') {
					temp += str[i];
					i++;
				}

				tmp.type = LEX_T_NUM;
				tmp.value = temp;		
			} else if (str[i] == '\'') {
				std::string temp = "";

				i++;
				while (str[i] && str[i] != '\'') {
					temp += str[i];
					i++;
				}
				i++;

				tmp.type = LEX_T_STR;
				tmp.value = temp;
			} else if (str[i] == '#') {
				while (str[i] != '\n')
					i++;
			} else {
				std::string msg = "Forbidden character '"; msg += str[i];
				msg += "'!";
				throw SyntaxException(error_notify(file, line, msg));
			}

			lex.push_back(tmp);
			tmp.type = LEX_T_INV;
			tmp.value = "";
		}
	}
}

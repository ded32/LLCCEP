#ifndef ASSEMBLER_LEXER_HPP
#define ASSEMBLER_LEXER_HPP

#include <string>
#include <vector>
#include <cstddef>
#include <cstdint>

#include <autoReleasePointer.hpp>

namespace LLCCEP_ASM {
	enum lex_t: uint8_t { 
		LEX_T_REG      = 0,
		LEX_T_MEM      = 1,
		LEX_T_VAL      = 2,
		LEX_T_COND     = 3,
		LEX_T_MACROARG = 4,
		LEX_T_NAME     = 5,
		LEX_T_MACRO    = 6,
		LEX_T_ENDMACRO = 7,
		LEX_T_VAR      = 8,
		LEX_T_RELEASE  = 9,
		LEX_T_NO       = 10,
		LEX_T_COLON    = 11,
		LEX_T_NEWLINE  = 12,
		LEX_T_INVALID  = 13
	};

	struct lexem {
		lex_t type;
		::std::string val;
		char numberSystem;

		struct lexemPosition {
			::std::string file;
			size_t line;
		} pos;
		
		LLCCEP::autoReleasePointer<lexem> expansionData;
	};

	class lexer {
	public:
		lexer();
		~lexer();
		
		void setProcessingPath(::std::string path);
		void setProcessingFile(::std::istream *in);
		void getNextLine(::std::vector<lexem> &lex);
	
		bool ok() const;
		
	protected:
		void lexerIssue(const char *fmt, ...);
		
	private:
		::std::string _path;
		size_t _line;
		::std::istream *_in;
		bool _started;
	};
	
	::std::string getLexemTypename(lex_t type);
	
	int64_t isInstruction(::std::string str);
	int64_t isCondition(::std::string str);
	bool isNumSystem(char c);
}

#endif // ASSEMBLER_LEXER_HPP

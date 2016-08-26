#ifndef CXXCB_HPP
#define CXXCB_HPP

#include <string>
#include <functional>
#include <utility>

namespace CxxCB {
	namespace CxxCBLexer {
		namespace DefaultRegex {
			const ::std::string IntegerRegex = "[0-9]+";
			const ::std::string RealRegex = "[0-9]+(\\.[0-9]+)?";
			const ::std::string LiteralStringRegex = "\"([^\"\\\\]|\\\\.)*\"";
		}

		class lexemType {
		public:
			lexemType();
			~lexemType();

			void regularExpression(::std::string val);
			::std::string regularExpression() const;
		
			void type(::std::string val);
			::std::string type() const;

			void action(::std::function<void(::std::pair<::std::string, ::std::string>)> val);
			::std::function<void(::std::pair<::std::string, ::std::string>)> action() const;

		private:
			::std::string regex;
			::std::string type;
			::std::function<void(::std::pair<::std::string, ::std::string>)> act;
		};

		class lexem {
		public:
			lexem();
			explicit lexem(lexemType typedataVal, ::std::string valueVal);
			~lexem();

		private:
			lexemType typedata;
			::std::string value;
		};

		class lexer {
		public:
			lexer();
			~lexer();

			 getNextLexem(::std::string &in);

		private:
			::std::vector<lexemType> lexemTypes;
		};
	}
}

#endif // CXXCB_HPP

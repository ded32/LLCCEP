#include <string>
#include <convert.hpp>

#include "ast.hpp"

struct testLexemType {
	::std::string name;
	int type;

	::std::string toString(bool enforceQuotes = true) const;
};

::std::string testLexemType::toString(bool enforceQuotes) const
{
	::std::string quote = ((enforceQuotes)?("\\\""):("\""));
	return quote + name + quote + ":" + to_string(type);
}

template<typename charT, typename traits>
::std::basic_ostream<charT, traits> &operator<<(::std::basic_ostream<charT, traits> &out, testLexemType lexem)
{
	out << lexem.toString(false); 
	return out;
}

int main()
{
	LLCCEP::ast<testLexemType> testAst(testLexemType{"testRoot", 0});
	testAst.addChild(LLCCEP::ast<testLexemType>(testLexemType{"testLeftNode", 1}));
	testAst.addChild(LLCCEP::ast<testLexemType>(testLexemType{"testRightNode", 1}));

	testAst.dumpImage("astDump");

	return 0;
}

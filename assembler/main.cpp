#include <fstream>
#include <iostream>
#include <cerrno>
#include <cstring>
#include <cstdlib>
#include <vector>

#include <STDExtras.hpp>
#include <command-line.hpp>

#define FILEFAIL(path, f) \
{ \
	if (f.fail()) { \
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG( \
			"Can't open '%s': %s", \
			path.c_str(), ::std::strerror(errno))) \
	} \
}

::std::string yyfilename;
extern FILE *yyin;

extern int yyparse(LLCCEP_ASM::sectionList **parsingResult);

int main(int argn, char **argv)
{	
	try {
		LLCCEP_ASM::sectionList **sectionList = NULL;
		size_t secno = 0;

		::std::string output = "a.exec";
		::std::vector<::std::string> input;

		commandLineParametersAssembler clp;
		clp.parse(argn, argv);

		if (clp.getOutput().length())
			output = clp.getOutput();

		for (const auto &i: input) {
			sectionList = (LLCCEP_ASM::sectionList **)realloc(sectionList, sizeof(sectionList *) * secno++);

			yyfilename = i;
			yyin = fopen(i.c_str(), "r");
			yyparse(&sectionList[secno - 1]);
		}
	} catch (::LLCCEP::runtime_exception &exc) {
		QUITE_ERROR(yes, "%s\n", exc.msg());
	} catch (...) {
		QUITE_ERROR(yes, "Unknown error!\n");
	}

	return 0;
}

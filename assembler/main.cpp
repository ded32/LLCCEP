#include <fstream>
#include <cstdio>
#include <cerrno>

void usage()
{
	::std::fprintf(stderr, "Usage:\n"
	                       "-h/-u show help(this text)\n"
	                       "-i files after are input\n"
	                       "-o file after is output\n"
	                       "If none output is provided, a.exec will be used.\n"
	                       "If none command-line params are given, this help is shown.\n");
}

int main(int argn, char * const *argv)
{
	if (argn < 2) {
		::std::fprintf(stderr, "Error!\nNo command-line params!");
		usage();
		return EINVAL;
	}

	
}

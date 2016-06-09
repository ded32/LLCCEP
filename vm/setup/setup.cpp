#include <vector>
#include <cstdint>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cerrno>

#include "./../conf/conf.hpp"
#include "setup.hpp"

static void __readFile2vec(::std::string path, ::std::vector<uint8_t> &vec)
{
	::std::ifstream in(path);

	if (in.fail()) {
		::std::fprintf(stderr, "Error!\nCan't open %s: %s!\n",
		               path.c_str(), ::std::strerror(errno));
	}

	in.seekg(0, in.end);
	size_t len = in.tellg();
	in.seekg(0, in.beg);

	char *buf = new char[len];
	in.read(buf, len);

	for (size_t i = 0; i < len - 1; i++)
		vec.push_back(buf[i]);
}

namespace LLCCEP_vm {
	double regs[32] = {};
	void *mem = 0;
	::std::vector<::std::vector<uint8_t> > dev;
	
	int dispW = 0;
	int dispH = 0;

	void setup_vm(config conf)
	{
		mem = calloc(1, conf.ramS);

		dispW = conf.displayW;
		dispH = conf.displayH;

		for (size_t i = 0; i < conf.dev.size(); i++) {
			::std::vector<uint8_t> tmp;
			__readFile2vec(cong.dev[i], tmp);

			dev.push_back(tmp);
		}
	}
}

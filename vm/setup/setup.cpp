#include <vector>
#include <cstdint>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cerrno>
#include <utility>

#include "./../conf/conf.hpp"
#include "setup.hpp"

static void __vm_load_dev(::LLCCEP_vm::config conf)
{
	for (size_t i = 0; i < conf.dev.size(); i++) {
		FILE *tmp = ::std::fopen(conf.dev[i].c_str(), "r+b");
		LLCCEP_vm::dev.push_back(tmp);
	}
}

namespace LLCCEP_vm {
	double regs[32] = {};
	void *mem = 0;

	int dispW = 0;
	int dispH = 0;

	::std::vector<FILE *> dev;

	void setup_vm(config conf)
	{
		mem = calloc(1, conf.ramS);

		dispW = conf.displayW;
		dispH = conf.displayH;

		__vm_load_dev(conf);
	}

	void free_vm_resources()
	{
		free(mem);

		for (size_t i = 0; i < dev.size(); i++)
			fclose(dev[i]);
	}
}

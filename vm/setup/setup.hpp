#ifndef SETUP_HPP
#define SETUP_HPP

#include <vector>
#include <cstdint>

#include "./../conf/conf.hpp"

namespace LLCCEP_vm {
	extern double regs[32];
	extern void *mem;
	extern ::std::vector<::std::fstream> dev;

	extern int dispW;
	extern int dispH;

	void setup_vm(config conf);
	void free_vm_resources();
}

#endif // SETUP_HPP

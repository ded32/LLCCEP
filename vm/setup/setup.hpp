#ifndef SETUP_HPP
#define SETUP_HPP

#include <vector>
#include <cstdint>

#include "./../conf/conf.hpp"

namespace LLCCEP_vm {
	extern double regs[32];
	extern void *mem;
	extern ::std::vector<::std::vector<uint8_t> > dev;

	extern int dispW;
	extern int dispH;

	void setup_vm(config conf);
}

#endif // SETUP_HPP

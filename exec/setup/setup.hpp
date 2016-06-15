#ifndef SETUP_HPP
#define SETUP_HPP

#include <vector>
#include <cstdint>
#include <cstdio>

#include "./../conf/conf.hpp"

namespace LLCCEP_vm {
	extern ::std::vector<FILE *> dev;

	void setup_vm_resources(config conf);
	void free_vm_resources();
}

#endif // SETUP_HPP

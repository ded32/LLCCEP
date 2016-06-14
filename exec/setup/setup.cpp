#include <vector>
#include <cstdint>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cerrno>
#include <utility>

#include "./../conf/conf.hpp"
#include "setup.hpp"

#include "./../drivers/display/display.hpp"
#include "./../drivers/ram/ram.hpp"

static void __vm_load_dev(::LLCCEP_vm::config conf)
{
	for (size_t i = 0; i < conf.dev.size(); i++) {
		FILE *tmp = ::std::fopen(conf.dev[i].c_str(), "r+b");
		LLCCEP_vm::dev.push_back(tmp);
	}
}

namespace LLCCEP_vm {
	::std::vector<FILE *> dev;

	void setup_vm(config conf)
	{
		__vm_load_dev(conf); // Open devices

		if (conf.displayW <= 0 || // Init display
		    conf.displayH <= 0) {
			init_display(conf.title.c_str(),  
			             get_host_width(),
			             get_host_height());
		} else {
			init_display(conf.title.c_str(),
			             conf.dispayW, conf.displayH);
		}

		allocate_mem(conf.memS); // Allocate VM RAM
	}

	void free_vm_resources()
	{
		free_mem();
		kill_display();

		for (size_t i = 0; i < dev.size(); i++)
			fclose(dev[i]);		
	}
}

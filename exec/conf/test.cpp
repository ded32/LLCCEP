#include <iostream>
#include "conf.hpp"

int main()
{
	LLCCEP_vm::config conf = LLCCEP_vm::read_configuration_file("test.cfg");
	::std::cout << "Screen: " << conf.displayW << "x" << conf.displayH << "\n" 
	            << "RAM: " << conf.ramS << "\n";

	for (size_t i = 0; i < conf.dev.size(); i++)
		::std::cout << "Dev[" << i << "]: " << conf.dev[i] << "\n";

	return 0;
}

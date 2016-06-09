#include <iostream>
#include "conf.hpp"

int main()
{
	LLCCEP_vm::config conf = LLCCEP_vm::read_configuration_file("test.cfg");
	::std::cout << "Screen: " << conf.displayW << "x" << conf.displayH << "\n" 
	            << "RAM: " << conf.ramS << "\n";

	return 0;
}

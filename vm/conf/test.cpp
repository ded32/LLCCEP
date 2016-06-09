#include <iostream>
#include "conf.hpp"

int main()
{
	LLCCEP_vm::config conf = LLCCEP_vm::read_configuration_file("test.cfg");
	::std::cout << conf.displayW << "x" << conf.displayH
	            << "\n" << conf.ramS;

	return 0;
}

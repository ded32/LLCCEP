#ifndef EMULATION_HPP
#define EMULATION_HPP

#include "../loader/loader.hpp"

namespace LLCCEP {
	bool Start();
	void run(inst& data);
	void Quit();	

	static double reg[32] = {};
}

#endif // EMULATION_HPP

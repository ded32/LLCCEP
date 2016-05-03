#ifndef STARTUP_HPP
#define STARTUP_HPP

#include <vector>
#include <cstdint>

#include "../emitter/emitter.hpp"
#include "program.hpp"

namespace LLCCEP_JIT {
	program make_program(emitter emit);
	void call(program data);
	void delete_program(program data);
}

#endif // STARTUP_HPP

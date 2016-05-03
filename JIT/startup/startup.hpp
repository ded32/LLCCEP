#ifndef STARTUP_HPP
#define STARTUP_HPP

#include <vector>
#include <cstdint>

#include "../emitter/emitter.hpp"
#include "program.hpp"

namespace LLCCEP_JIT {
	sys::program make_program(emitter emit);
	void call(sys::program data);
	void delete_program(sys::program data);
}

#endif // STARTUP_HPP

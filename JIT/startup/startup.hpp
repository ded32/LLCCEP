#ifndef STARTUP_HPP
#define STARTUP_HPP

#include <vector>
#include <cstdint>

#include "program.hpp"
#include "../emitter/emitter.hpp"

namespace LLCCEP_JIT {
	program_exec_data make_program(emitter emit);
	void call(program_exec_data data);
	void delete_program(program_exec_data data);
}

#endif // STARTUP_HPP

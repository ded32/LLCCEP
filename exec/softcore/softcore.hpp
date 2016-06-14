#ifndef SOFTCORE_HPP
#define SOFTCORE_HPP

#include <vector>
#include "./../program.hpp"

#if defined(VM_EXECUTION)
#define VM 1
#else
#define VM 0
#endif

namespace LLCCEP_vm {
	void execute(::std::vector<instruction> &data);
}

#endif // SOFT_CORE_HPP

#include <cstdint>

#include "./../display/display.hpp"
#include "kb.hpp"

namespace LLCCEP_vm {
	void get_key_state(uint8_t code)
	{
		return __sys__::__kb__::keys[code];
	}
}

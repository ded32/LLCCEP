#include <cstdint>

#include "./../display/display.hpp"
#include "kb.hpp"

namespace LLCCEP_vm {
	bool get_key_state(uint8_t code)
	{
		return get_captured_kb_state(code);
	}
}

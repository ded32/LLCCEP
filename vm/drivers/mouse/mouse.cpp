#include "./../display/display.hpp"
#include "mouse.hpp"

namespace LLCCEP_vm {
	inline unsigned get_mouse_x()
	{
		return get_captured_mouse_x();
	}

	inline unsigned get_mouse_y()
	{
		return get_captured_mouse_y();
	}

	inline unsigned get_mouse_buttons_state()
	{
		return get_captured_mouse_buttons_state();
	}
}

#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <string>

namespace LLCCEP_vm {
	bool init_display(::std::string title, int width, int height);
	void handle_msg();
	void set_clr(uint32_t clr);
	uint32_t get_clr();
	void set_pix(int posX, int posY);
	uint32_t get_pix(int posX, int posY);
	void kill_display();
}

#endif // DISPLAY_HPP

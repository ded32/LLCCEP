#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <string>

#if !defined(RGBA) && !defined(RGB)
#define RGBA(r, g, b, a) (((a) & 0xFF) << 24) | \
                         (((b) & 0xFF) << 16) | \
                         (((g) & 0xFF) <<  8) | \
                          ((r) & 0xFF)

#define RGB(r, g, b) RGBA(r, g, b, 0xFF)
#endif

#if !defined(RGBA_R) && !defined(RGBA_G) && \
    !defined(RGBA_B) && !defined(RGBA_A)
#define RGBA_R(clr) ((clr) & 0xFF)
#define RGBA_G(clr) (((clr) >>  8) & 0xFF)
#define RGBA_B(clr) (((clr) >> 16) & 0xFF)
#define RGBA_A(clr) (((clr) >> 24) & 0xFF)
#endif

namespace LLCCEP_vm {
	bool init_display(::std::string title, int width, int height);
	bool handle_msg();

	void set_clr(uint32_t clr);
	uint32_t get_clr();

	void set_pix(int posX, int posY);
	uint32_t get_pix(int posX, int posY);

	int get_host_width();
	int get_host_height();

	bool get_captured_kb_state(uint8_t id);
	unsigned get_captured_mouse_x();
	unsigned get_captured_mouse_y();
	unsigned get_captured_mouse_buttons_state();

	void kill_display();
}

#endif // DISPLAY_HPP

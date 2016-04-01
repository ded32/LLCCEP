#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <cstdint>

typedef uint32_t COLORREF;
#define RGB(r, g, b) (((b & 0xFF) << 16) | ((g & 0xFF) << 8) | (b & 0xFF))
#define RGBR(clr) (clr & 0xFF)
#define RGBG(clr) ((clr >> 8) & 0xFF)
#define RGBB(clr) ((clr >> 16) & 0xFF)

namespace LLCCEP {
	bool init_sdl();
	bool init_window();
	bool init_renderer();

	void set_pixel(int x, int y);
	void set_color(COLORREF clr);

	int get_screen_width();
	int get_screen_height();
}

#endif // WINDOW_HPP

#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SDL2/SDL.h>
#include <cstdint>

#define RGBA(r, g, b, a) \
(((a) & 0xFF) << 24) | \
(((b) & 0xFF) << 16) | \
(((g) & 0xFF) <<  8) | \
((r) & 0xFF)

#define RGBA_R(clr) ((clr) & 0xFF)
#define RGBA_G(clr) (((clr) >>  8) & 0xFF)
#define RGBA_B(clr) (((clr) >> 16) & 0xFF)
#define RGBA_A(clr) (((clr) >> 24) & 0xFF)

#define RGB(r, g, b) RGBA(r, g, b, 0)
#define RGB_R RGBA_R
#define RGB_G RGBA_G
#define RGB_B RGBA_B

namespace LLCCEP_vm {
	typedef struct {
		int X;
		int Y;
	} size, point;

	class window {
		SDL_Window *wnd;
		SDL_Renderer *rnd;
		bool running;
		bool shown;
		bool mouse_focused;
		bool kb_focused;
	public:
		window();
		~window();

		void create(char * const title,
		            size metrics,
		            point pos,
		            uint32_t flags);

		void handle(SDL_Event &ev);

		void set_color(uint32_t color);
		uint32_t get_color() const;

		void set_pixel(int x, int y, uint32_t color);
		uint32_t get_pixel(int x, int y) const;

		void clear(uint32_t clr = get_color());

		size get_min_size() const;
		size get_size()     const;
		size get_max_size() const;

		void set_min_size(size min_sz);
		void set_size(size sz);
		void set_max_size(size max_sz);

		void make_fullscreen();
		void hide();
		void show();
		void minimize();
		void maximize();
		void grab(bool mode = true);

		void update();
		void destroy();
	};
}

#endif // WINDOW_HPP

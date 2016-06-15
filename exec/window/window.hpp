#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SDL2/SDL.h>
#include <cstdint>
#include <string>

namespace LLCCEP_vm {
	class window {
		SDL_Window *wnd;
		SDL_Renderer *rnd;
		int id;
		bool running;
	public:
		window();

		void init(::std::string title,
		          uint16_t width,
		          uint16_t height);

		void handle();

		void set_clr(uint32_t clr);
		uint32_t get_clr();

		void set_pix(uint16_t x, uint16_t y);
		uint32_t get_pix(uint16_t x, uint16_t y);

		void close();

		~window();
	};

	unsigned get_screen_width();
	unsigned get_screen_height();
}

#endif // WINDOW_HPP

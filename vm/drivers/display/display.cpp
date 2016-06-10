#include <SDL2/SDL.h>
#include <cstdio>
#include <string>

#include "display.hpp"

#define INIT_FAIL(cond) \
({ \
	if (cond) { \
		::std::fprintf(stderr, "Error!\n" \
		               "Can't init display: %s!\n", \
		               SDL_GetError()); \
		\
		return false; \
	} \
});

namespace LLCCEP_vm {
	namespace __sys__ {
		SDL_Window *window = 0;
		SDL_Renderer *renderer = 0;

		namespace __kb__ {
			bool keys[256] = {};
		}

		namespace __mouse__ {
			int x = 0;
			int y = 0;
			uint32_t buttons = 0;
		}
	}

	bool init_display(::std::string title, int width, int height)
	{
		INIT_FAIL(SDL_Init(SDL_INIT_EVERYTHING != 0))

		__sys__::window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED,
		                                   SDL_WINDOWPOS_CENTERED, width, height,
		                                   SDL_WINDOW_SHOWN);
		INIT_FAIL(!__sys__::window)

		__sys__::renderer = SDL_CreateRenderer(__sys__::window, -1,
		                                       SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		INIT_FAIL(!__sys__::renderer)

		set_clr(RGB(0x0, 0x0, 0x0));
		SDL_RenderClear(__sys__::renderer);

		return true;
	}

	bool handle_msg() 
	{
		SDL_Event ev = {};

		while (SDL_PollEvent(&ev)) {
			switch (ev.type) {
				case SDL_QUIT:
					return false;
					break;

				case SDL_KEYDOWN:
					__sys__::__kb__::keys[ev.key.keysym.scancode] = true;
					break;

				case SDL_KEYUP:
					__sys__::__kb__::keys[ev.key.keysym.scancode] = false;
					break;

				case SDL_MOUSEMOTION:
					__sys__::__mouse__::x = ev.motion.x;
					__sys__::__mouse__::y = ev.motion.y;
					__sys__::__mouse__::buttons = ev.motion.state;
					break;

				case SDL_MOUSEBUTTONDOWN:
					__sys__::__mouse__::x = ev.button.x;
					__sys__::__mouse__::y = ev.button.y;
					__sys__::__mouse__::buttons |= ev.button.button;
					break;

				case SDL_MOUSEBUTTONUP:
					__sys__::__mouse__::x = ev.button.x;
					__sys__::__mouse__::y = ev.button.y;
					__sys__::__mouse__::buttons &= ~(ev.button.button);
					break;

				default:
					break;
			}

			SDL_RenderPresent(__sys__::renderer);
			SDL_UpdateWindowSurface(__sys__::window);
		}

		return true;
	}

	void set_clr(uint32_t clr)
	{
		SDL_SetRenderDrawColor(__sys__::renderer,
		                       RGBA_R(clr),
		                       RGBA_G(clr),
		                       RGBA_B(clr),
		                       RGBA_A(clr));
	}

	uint32_t get_clr()
	{
		uint32_t res = 0;
		SDL_GetRenderDrawColor(__sys__::renderer,
		                       ((uint8_t *)&res) + 3 * sizeof(uint8_t),
		                       ((uint8_t *)&res) + 2 * sizeof(uint8_t),
		                       ((uint8_t *)&res) + 1 * sizeof(uint8_t),
		                       ((uint8_t *)&res) + 0 * sizeof(uint8_t));

		return res;
	}

	void set_pix(int posX, int posY)
	{
		SDL_RenderDrawPoint(__sys__::renderer, posX, posY);
	}

	uint32_t get_pix(int posX, int posY)
	{
		SDL_Surface *sfc = SDL_GetWindowSurface(__sys__::window);
		uint32_t *pix = (uint32_t *)sfc->pixels;

		return pix[(posY * sfc->w) + posX];
	}

	void kill_display()
	{
		SDL_DestroyRenderer(__sys__::renderer);
		SDL_DestroyWindow(__sys__::window);
		SDL_Quit();
	}
}

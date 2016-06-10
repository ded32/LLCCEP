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
	}

	bool init_display(::std::string title, int width, int height)
	{
		INIT_FAIL(SDL_Init(SDL_INIT_EVERYTHING != 0))

		__sys__::window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED,
		                                   SDL_WINDOWPOS_CENTERED, width, height,
		                                   SDL_WINDOW_SHOWN);
		INIT_FAIL(!__sys__::window)

		__sys__::renderer = SDL_CreateRenderer(__sys__::window, -1,
		                                       SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENT_VSYNC);
		INIT_FAIL(!__sys__::renderer)

		SDL_RendererClean(__sys__::renderer);
	}

	void handle_msg() 
	{
		
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
		                       ((uint8_t *)&res)[3],
		                       ((uint8_t *)&res)[2],
		                       ((uint8_t *)&res)[1],
		                       ((uint8_t *)&res)[0]);

		return res;
	}

	void set_pix(int posX, int posY)
	{
		SDL_RenderDrawPoint(__sys__::renderer, posX, posY);
	}

	uint32_t get_pix(int posX, int posY)
	{
		SDL_Surface *sfc = SDL_GetWindowSurface(__sys__::window);
		UInt32 *pix = (UInt32 *)sfc->pixels;

		return pix[(posY * sfc->width) + posX];
	}

	void kill_display()
	{
		SDL_DestroyRenderer(__sys__::renderer);
		SDL_DestroyWindow(__sys__::window);
		SDL_Quit();
	}
}

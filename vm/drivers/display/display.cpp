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

	void kill_display()
	{
		SDL_DestroyRenderer(__sys__::renderer);
		SDL_DestroyWindow(__sys__::window);
		SDL_Quit();
	}
}

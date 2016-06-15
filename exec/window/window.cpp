#include <SDL2/SDL.h>
#include <cstdint>
#include <string>

#define INIT_FAIL(expr) \
if (expr) { \
	throw RUNTIME_EXCEPTION(CONSTRUCT_MSG( \
		"Error!\n" \
		"Can't create window: %s", \
		SDL_GetError())); \
}

#define OPENED_FATAL \
if (wnd || rnd || running) { \
	throw RUNTIME_EXCEPTION(CONSTRUCT_MSG( \
		"Error!\n" \
		"%s requests window not beeing opened!", \
		__PRETTY_FUNCTION__)); \
}

#define NOT_OPENED_FATAL \
if (!wnd || !rnd || !running) { \
	throw RUNTIME_EXCEPTION(CONSTRUCT_MSG( \
		"Error!\n" \
		"%s requests window beeing opened", \
		__PRETTY_FUNCTION__)); \
}

namespace LLCCEP_vm {
	bool __sdl_running__ = false;
	size_t __windows_n__ = 0;
	::std::vector<window *> windows;

	window::window():
		wnd(0),
		rnd(0),
		id(0),
		running(false)
	{ }

	void window::init(::std::string title,
	                  uint16_t width,
	                  uint16_t height)
	{
		OPENED_FATAL

		if (!__sdl_running__) {
			INIT_FATAL(SDL_Init(SDL_INIT_EVERYTHING))
			__sdl_running = true;
		}

		wnd = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED,
		                       SDL_WINDOWPOS_CENTERED, width, height,
		                       SDL_WINDOW_SHOWN);
		INIT_FATAL(!wnd)

		rnd = SDL_CreateRenderer(wnd, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		INIT_FAIL(!rnd);

		__windows_n__++;
	}
}

#if defined(__APPLE__)
#	include <SDL2/SDL.h>
#else
#	include <SDL.h>
#endif

#include <cstdint>
#include <iostream>
#include <cassert>

#include "window.hpp"

namespace LLCCEP {
	namespace SYS {
		SDL_Window *wnd = 0;
		SDL_Renderer *rnd = 0;
	}

	bool init_sdl()
	{
		if (SDL_Init(SDL_INIT_EVERYTHING)) {
			std::cerr << "Error!\n" << "Can't init SDL: " << SDL_GetError() << "!\n";
			return false;
		}

		return true;
	}

	bool init_window()
	{
		SYS::wnd = SDL_CreateWindow("Emulation", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		                            get_screen_width(), get_screen_height(), SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN);
		if (!SYS::wnd) {
			std::cerr << "Error!\n" << "Can't init window: " << SDL_GetError() << "!\n";
			return false;
		}

		return true;
	}

	bool init_renderer()
	{
		SYS::rnd = SDL_CreateRenderer(SYS::wnd, -1, SDL_RENDERER_ACCELERATED);
		if (!SYS::rnd) {
			std::cerr << "Error!\n" << "Can't init renderer: " << SDL_GetError() << "!\n";
			return false;
		}

		SDL_RenderClear(SYS::rnd);
		return true;
	}

	void set_pixel(int x, int y)
	{
		assert(SYS::wnd && SYS::rnd);
		SDL_RenderDrawPoint(SYS::rnd, x, y);
	}	

	void set_color(COLORREF clr)
	{
		assert(SYS::wnd && SYS::rnd);
		SDL_SetRenderDrawColor(SYS::rnd, RGBR(clr), RGBB(clr), RGBG(clr), 0xFF);
	}

	int get_screen_width()
	{
		SDL_DisplayMode mode = {};
		SDL_GetCurrentDisplayMode(0, &mode);
		
		return mode.w;
	}

	int get_screen_height()
	{
		SDL_DisplayMode mode = {};
		SDL_GetCurrentDisplayMode(0, &mode);

		return mode.h;
	}

	void Delay(uint64_t time)
	{
		clock_t begin = clock();
		while ((begin + time * 1000 / CLOCKS_PER_SEC) > clock());
	}

	void PresentSurface()
	{
		SDL_RenderPresent(SYS::rnd);
		SDL_UpdateWindowSurface(SYS::wnd);
	}
}

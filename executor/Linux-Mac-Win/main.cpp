#if defined(__APPLE__)
#	include <SDL2/SDL.h>
#else
#	include <SDL.h>
#endif

#include <iostream>
#include <vector>

#include "emulation/emulation.hpp"
#include "loader/loader.hpp"
#include "window/window.hpp"

int main(int argn, const char **argv)
{
	if (argn <= 1) {
		std::cerr << "Error!\nNo input!\n";
		return EINVAL;
	}

	bool quit = false;

	std::vector <LLCCEP::inst> program;
	for (int i = 1; i < argn; i++)
		LLCCEP::LoadProgram(argv[i], program);

	LLCCEP::Start();
	LLCCEP::reg[14] = 1;

	while (!quit) {
		SDL_Event ev = {};
		while (SDL_PollEvent(&ev)) {
			switch(ev.type) {
				case SDL_QUIT:
					quit = true;
					break;

				case SDL_KEYDOWN:
					if (ev.key.keysym.sym == SDLK_ESCAPE)
						quit = true;
					break;

				default:
					break;
			}
		}

		if (LLCCEP::reg[14] <= program.size()) {
			LLCCEP::run(program[LLCCEP::reg[14] - 1]);
			LLCCEP::reg[14]++;
		} else
			quit = true;
		
		LLCCEP::PresentSurface();
	}

	quit = false;
	while (!quit) {
		int num = 0;
		const Uint8 *state = SDL_GetKeyboardState(&num);
	
		for (int i = 0; i < num; i++)
			if (state[i])
				quit = true;
	}	

	LLCCEP::Quit();

	return 0;
}

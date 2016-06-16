#include <SDL2/SDL.h>
#include <cstdint>

#define INIT_FATAL(expr) \
({ \
if (!(expr)) { \
	throw RUNTIME_EXCEPTION(CONSTRUCT_MSG( \
		"Error!\n" \
		"Window initialization failed: %s", \
		SDL_GetError())); \
} \
})

#define NON_RUNNING_FATAL \
({ \
if (!running || !wnd || !rnd) { \
	throw RUNTIME_EXCEPTION(CONSTRUCT_MSG( \
		"Error!\n" \
		"Window requested beeing running in %s function", \
		__PRETTY_FUNCTION__)); \
} \
})

#define RUNNING_FATAL \
({ \
if (running || wnd || rnd) { \
	throw RUNTIME_EXCEPTION(CONSTRUCT_MSG( \
		"Error!\n" \
		"Window requested not beeing running in %s function!\n", \
		__PRETTY_FUNCTION__)); \
} \
})

namespace LLCCEP_vm {
	namespace __wnd__ {
		bool initialized = 0;
		size_t n_windows = 0;
	}

	window::window():
		wnd(0),
		rnd(0),
		running(false),
		shown(false),
		mouse_focused(false),
		kb_focused(false)
	{
		if (!__wnd__::initialized)
			SDL_Init(SDL_INIT_EVERYTHING);

		__wnd__::n_windows++;
	}

	window::~window()
	{
		destroy();
		__wnd__::n_windows--;
	}

	void window::create(char * const title,
	                    size metrics,
	                    point pos,
                            uint32_t flags)
	{
		RUNNING_FATAL

		wnd = SDL_CreateWindow(title, pos.x, pos.y,
		                       metrics.x, metrics.y, flags);
		INIT_FATAL(!wnd)

		rnd = SDL_CreateRenderer(wnd, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

		INIT_FATAL(!rnd)

		set_color(RGB(0xFF, 0xFF, 0xFF));
		clear();
		set_color(RGB(0x00, 0x00, 0x00));
	}

	void window::handle(SDL_Event &ev)
	{
		NON_RUNNING_FATAL

		int id = SDL_GetWindowID(wnd);
		if (ev.type == SDL_WINDOWEVENT && ev.window.windowID == ID) {
			switch (ev.window.event) {
				case SDL_WINDOWEVENT_SHOWN:
					shown = false;
					break;

				case SDL_WINDOWEVENT_HIDDEN:
					shown = false;
					break;

				case SDL_WINDOWEVENT_SIZE_CHANGED:
					update();
					break;

				case SDL_WINDOWEVENT_EXPOSED:
					update();
					break;

				case SDL_WINDOWEVENT_ENTER:
					mouse_focused = true;
					break;

				case SDL_WINDOWEVENT_LEAVE:
					mouse_focused = false;
					break;

				case SDL_WINDOWEVENT_FOCUS_GAINED:
					kb_focused = true;
					break;

				case SDL_WINDOWEVENT_FOCUS_LOST:
					kb_focused = false;
					break;

				case SDL_WINDOWEVENT_CLOSE:
					SDL_HideWindow(wnd);
					break;

				default:
					break;
			}
		}
	}

	void window::set_color(uint32_t color)
	{
		NON_RUNNING_FATAL

		SDL_SetRenderDrawColor(rnd,
		                       RGBA_R(color),
		                       RGBA_G(color),
		                       RGBA_B(color),
		                       RGBA_A(color));
	}

	uint32_t window::get_color() const
	{
		NON_RUNNING_FATAL

		uint32_t clr = 0;
		uint8_t *r = &(((uint8_t *)&clr)[3]);
		uint8_t *g = &(((uint8_t *)&clr)[2]);
		uint8_t *b = &(((uint8_t *)&clr)[1]);
		uint8_t *a = ((uint8_t *)&clr);

		SDL_GetRenderDrawColor(rnd, r, g, b, a);

		return clr;
	}

	void window::set_pixel(int x, int y, uint32_t color)
	{
		NON_RUNNING_FATAL

		uint32_t clr = get_color();

		set_color(color);
		SDL_RenderDrawPoint(rnd, x, y);
		set_color(clr);
	}

	uint32_t window::get_pixel(int x, int y) const
	{
		NON_RUNNING_FATAL

		uint32_t *pix = (uint32_t *)(SDL_GetWindowSurface(wnd)->pixels);

		return pix[y * get_size().x + x];
	}

	void window::clear(uint32_t clr)
	{
		NON_RUNNING_FATAL

		uint32_t tmp = get_color();
		set_color(clr);
		SDL_RenderClear(rnd);
		set_color(tmp);
	}

	size window::get_min_size() const
	{
		NON_RUNNING_FATAL

		size res = {};
		SDL_GetWindowMinimumSize(wnd, &res.x, &res.y);
		return res;
	}

	size window::get_size() const
	{
		NON_RUNNING_FATAL

		size res = {};
		SDL_GetWindowSize(wnd, &res.x, &res.y);
		return res;
	}

	size window::get_max_size() const
	{
		NON_RUNNING_FATAL

		size res = {};
		SDL_GetWindowMaximumSize(wnd, &res.x, &res.y);
		return res;
	}

	void window::make_fullscreen()
	{
		NON_RUNNING_FATAL

		SDL_SetWindowFullScreen(wnd, SDL_WINDOW_FULLSCREEN);
	}

	void window::hide()
	{
		NON_RUNNING_FATAL

		SDL_HideWindow(wnd);
	}

	void window::show()
	{
		NON_RUNNING_FATAL

		SDL_ShowWindow(wnd);
	}

	void window::minimize()
	{
		NON_RUNNING_FATAL

		SDL_MinimizeWindow(wnd);
	}

	void window::maximize()
	{
		NON_RUNNING_FATAL

		SDL_MaximizeWindow(wnd);
	}

	void window::grab(bool mode)
	{
		NON_RUNNING_FATAL

		SDL_SetWindowGrab(wnd, static_cast<int>(mode));
	}

	void window::update()
	{
		NON_RUNNING_FATAL

		SDL_RenderPresent(rnd);
		SDL_UpdateWindowSurface(wnd);
	}

	void window::destroy()
	{
		NON_RUNNING_FATAL

		SDL_DestroyRenderer(rnd);
		SDL_DestroyWindow(wnd);

		rnd = false;
		wnd = false;
		running = false;
	}
}

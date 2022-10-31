#include "video.hh"
#include "constants.hh"
#include "util.hh"
#include "game.hh"

void VideoComponents::Init() {
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_JOYSTICK ) < 0) {
		Util::Error("Failed to initialise SDL: %s\n", SDL_GetError());
	}

    SDL_SetHint(SDL_HINT_RENDER_DRIVER, "opengl");
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

	#ifdef __vita__
		// VITA: The psvita does not generate mouse events
		SDL_SetHint(SDL_HINT_TOUCH_MOUSE_EVENTS, "0");
	#endif

	window = SDL_CreateWindow(
		(std::string(APP_NAME) + " " + APP_VERSION).c_str(),
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		APP_SCREEN_SIZE_W, APP_SCREEN_SIZE_H,
		SDL_WINDOW_RESIZABLE
	);

	if (window == nullptr) {
		Util::Error("Failed to create window: %s", SDL_GetError());
	}
	Util::Log("Created window");
	
	renderer = SDL_CreateRenderer(
		window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
	);

	if (renderer == nullptr) {
		Util::Error("Failed to create renderer: %s", SDL_GetError());
	}
	Util::Log("Created renderer");

	SDL_RenderSetLogicalSize(renderer, APP_SCREEN_SIZE_W, APP_SCREEN_SIZE_H);
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
}

void VideoComponents::Free() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}
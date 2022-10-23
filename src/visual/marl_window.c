#include <marl_window.h>


MARL_Window *MARL_CreateWindow(const char *title, int x, int y, int w, int h) {
	if(SDL_WasInit(SDL_INIT_VIDEO) == 0) {
		if(SDL_Init(SDL_INIT_VIDEO) != 0) {
			SDL_Log("Unable to initialize SDL video subsystem: %s", SDL_GetError());
			return NULL;
		}
	}
	MARL_Window *win = malloc(sizeof(MARL_Window));
	win->sdlWindow = SDL_CreateWindow(title, x, y, w, h, SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

	if(win->sdlWindow == NULL) {
		SDL_Log("Failed to create SDL window: %s", SDL_GetError());
		return NULL;
	}

	win->sdlRenderer = SDL_CreateRenderer(win->sdlWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_RenderClear(win->sdlRenderer);
	SDL_RenderPresent(win->sdlRenderer);

	return win;
}


void MARL_DestroyWindow(MARL_Window *window) {
	SDL_DestroyRenderer(window->sdlRenderer);
	SDL_DestroyWindow(window->sdlWindow);
	free(window);
	return;
}

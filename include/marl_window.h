#ifndef MARL_WINDOW_H
#define MARL_WINDOW_H

#include <marl.h>

typedef struct MARL_Window {
	SDL_Window *sdlWindow;
	SDL_Renderer *sdlRenderer;
} MARL_Window;



MARL_Window *MARL_CreateWindow(const char *title,int x, int y, int w, int h);

void MARL_DestroyWindow(MARL_Window *window);

#endif

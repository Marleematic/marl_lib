
#include "marl.h"

void print_meow() {
	printf("Meow!\n");
	int r = SDL_Init(SDL_INIT_VIDEO);

	if(r) {
		printf("Error: %s\n", SDL_GetError());
	} else {
		printf("SDL initialized successfully!\n");
		SDL_Quit();
	}
}


#include <marl_loop.h>

MARL_Loop *MARL_CreateLoop(unsigned int cap) {
	MARL_Loop *loop = malloc(sizeof(MARL_Loop));
	loop->nextRun = SDL_GetTicks64() + cap;
	loop->cap = cap;
	loop->iteration = 0;

	return loop;
}


void MARL_LoopWait(MARL_Loop *loop, SDL_Event *event) {
	
	if(SDL_PollEvent(event)) {
		return;
	}

	if(loop->nextRun >= SDL_GetTicks64() && !SDL_PollEvent(event)) {
		SDL_Delay(loop->nextRun - SDL_GetTicks64());
	}

	loop->nextRun += loop->cap;
	loop->iteration++;
}

void MARL_LoopCatchUp(MARL_Loop *loop) {
	loop->nextRun = SDL_GetTicks64() + loop->cap;
}

void MARL_DestroyLoop(MARL_Loop *loop) {
	free(loop);
	loop = 0;
	return;
}

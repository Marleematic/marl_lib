#include <marl_loop.h>

MARL_Loop *MARL_CreateLoop(unsigned int cap) {
	MARL_Loop *loop = malloc(sizeof(MARL_Loop));
	loop->nextRun = SDL_GetTicks64();
	loop->cap = cap;
	loop->iteration = 0;

	return loop;
}


int MARL_LoopWait(MARL_Loop *loop, SDL_Event *event) {
	
	if(SDL_PollEvent(event)) {
		return 1;
	}

//	printf("fps: %5f\n",1000.0f / (SDL_GetTicks64() - loop->nextRun));
	int k = 0;
	if(loop->nextRun + loop->cap > SDL_GetTicks64()) {
	//	printf("start sleep: %i \n", loop->cap - SDL_GetTicks64() + loop->nextRun);
		SDL_Delay((loop->nextRun+loop->cap)- SDL_GetTicks64());
	} 
	else {
//		SDL_Delay(3);
		k = 2;
	}
	/*//	printf("p: %i\n", SDL_GetTicks64() - (loop->nextRun + loop->cap));
		return 0;
	}*/
	loop->nextRun = SDL_GetTicks64();
	loop->iteration++;
	return k;
}

void MARL_LoopCatchUp(MARL_Loop *loop) {
	loop->nextRun = SDL_GetTicks64() + loop->cap;
}

void MARL_DestroyLoop(MARL_Loop *loop) {
	free(loop);
	loop = 0;
	return;
}

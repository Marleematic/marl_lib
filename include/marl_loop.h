#ifndef MARL_LOOP_H
#define MARL_LOOP_H

#include <marl.h>

typedef struct MARL_Loop {
	Uint64 nextRun;
	Uint64 cap; // min time to wait in ms
	Uint64 iteration;
} MARL_Loop;

MARL_Loop *MARL_CreateLoop(unsigned int cap);


void MARL_LoopWait(MARL_Loop *loop, SDL_Event *event);

void MARL_LoopCatchUp(MARL_Loop *loop);

void MARL_DestroyLoop(MARL_Loop *loop);


#endif

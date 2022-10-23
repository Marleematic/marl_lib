#ifndef MARL_WIDGET_H
#define MARL_WIDGET_H

#include "marl.h"

#define MARL_BUTTON = 0x1;


typedef struct MARL_WidgetInfo {
	unsigned int type;
	unsigned int depth;
	struct MARL_Widget *
} MARL_WidgetInfo;


typedef struct MARL_Button {
	MARL_WidgetInfo *info;
} MARL_Button;


typedef union MARL_Widget {
	MARL_WidgetInfo *info;
	MARL_Button button;

	// XXX Padding? See: https://github.com/libsdl-org/SDL/blob/main/include/SDL_events.h
} MARL_Widget;



MARL_WidgetInfo *MARL_WidgetCreateInfo(unsigned int type, unsigned int depth);


void MARL_WidgetHandleEvent(MARL_Widget *widget, SDL_Event *event);



#endif

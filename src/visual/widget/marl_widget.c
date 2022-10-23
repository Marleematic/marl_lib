#include "marl_widget.h"

void MARL_WidgetHandleEvent(MARL_Widget *widget, SDL_Event *event) {
	switch(widget->info->type) {
		case MARL_BUTTON:
			SDL_Log("Event for Button!");
			break;
		default:
			SDL_LOG("Event for unknown widget!");
	
	}
}

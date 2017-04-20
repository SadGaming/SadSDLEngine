#include "EventHandler.h"
#include "../SDLInclude.h"
#include <iostream>
EventHandler* EventHandler::gInstance = NULL;

EventHandler* EventHandler::getInstance()
{
	

	if(gInstance==NULL) {
		gInstance = new EventHandler();
	}
	return gInstance;
}

void EventHandler::poll()
{
	
	eventsByType.clear();
	SDL_Event e;
	
	while (SDL_PollEvent(&e)) {
		
		eventsByType[e.type].push_back(e);
	}
}
std::vector<SDL_Event> EventHandler::getEvents(Uint32 type) {
	if (eventsByType.count(type)>0) {
		return eventsByType[type];
	}
	
	/*for (Uint32 i = 0; i < events.size(); i++) {
		if(events[i].type == type){
			return &events[i];
		}
	}*/
	return std::vector<SDL_Event>();
}
bool EventHandler::containsEvent(Uint32 type){
	return (eventsByType.count(type) > 0) ? true : false;
		
}
EventHandler::EventHandler()
{
	
}


EventHandler::~EventHandler()
{
}

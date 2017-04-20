#ifndef EVENT_H
#define EVENT_H
#include "../SDLInclude.h"
#include <vector>
#include <map>
class EventHandler
{
public:
	
	static EventHandler* getInstance();
	void poll();
	std::vector<SDL_Event> getEvents(Uint32 type);
	bool containsEvent(Uint32 type);
	
	std::vector<SDL_Event> events;
	std::map<Uint32, std::vector<SDL_Event> > eventsByType;
private:
	EventHandler();
	~EventHandler();
	static EventHandler* gInstance;
	static int callCount;
};
#endif

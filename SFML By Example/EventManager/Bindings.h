#ifndef BINDINGS_H
#define BINDINGS_H

#include "EventType.h"
#include "EventInfo.h"
#include "EventDetails.h"
#include <vector>
#include <pair>
#include <string>
#include <unordered_map>

using Events = std::vector<std::pair<EventType, EventInfo>>;

struct Binding
{
	Binding(const std::string& name)
		: _name(name)
		, _details(name)
		, _c(0) {}

	void BindEvent(EventType type, EventInfo info = EventInfo())
	{
		_events.emplace_back(type, info);
	}

	Events      _events;
	std::string _name;
	int         _c;      // Count of events that are "Happening"

	EventDetails _details;
};

using Bindings = std::unordered_map<std::string, Binding*>;

#endif

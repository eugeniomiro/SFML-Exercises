#include "EventManager.h"

EventManager::EventManager() : _hasFocus(true) { LoadBindings(); }

EventManager::~EventManager()
{
	for (auto &itr: _bindings)
	{
		delete itr.second;
		itr.second = nullptr;
	}
}

void EventManager::LoadBindings()
{
}

bool EventManager::AddBindings(Binding *binding)
{
	if (_bindings.find(_binding->_name) != _bindings.end())
	{
		return false;
	}
	return _bindings.emplace(binding._name, binding).second;
}



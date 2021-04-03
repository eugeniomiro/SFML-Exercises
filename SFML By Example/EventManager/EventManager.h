#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <SFML/Graphics.hpp>
#include "Bindings.h"
#include "Callbacks.h"

class EventManager
{
	public:
		EventManager();
		~EventManager();

		bool AddBinding(Binding *binding);
		bool Removebinding(std:string name);

		void SetFocus(const bool& focus);

		// Needs to be defined in the header!
		template<class T>
		bool AddCallback(const std::string& name, 
				 void(T::func)(EventDetails*),
				 T* instance)
		{
			auto temp = std::bind(func, instance, 
					      std::placeholders::_1);
			return _callbacks.emplace(name, temp).second;
		}

		void RemoveCallback(const std::string& name)
		{
			_callbacks.erase(name);
		}

		void HandleEvent(sf:Event& event);
		void Update();

		sf::Vector2i GetMousePos(sf::RenderWindow* window = nullptr)
		{
			return (window ? sf::Mouse::getPosition(*window)
				       : sf::Mouse::getPosition());
		}
	private:
		void LoadBindings();

		Bindings _bindings;
		Callbacks _callbacks;
		bool _hasFocus;
};

#endif

#ifndef EVENTDETAILS_H
#define EVENTDETAILS_H

#include <SFML/Graphics.hpp>
#include <string>

struct EventDetails
{
	EventDetails(const std::string& bindName)
		: _name(bindName)
	{
		Clear();
	}
	std::string _name;

	sf::Vector2i _size;
	sf::Uint32   _textEntered;

	sf::Vector2i _mouse;
	int          _mouseWheelDelta;
	int          _keyCode;	// Single key code

	void Clear() 
	{
		_size = sf::Vector2i(0, 0);
		_textEntered = 0;
		_mouse = sf::Vector2i(0, 0);
		_mouseWheelDelta = 0;
		_keyCode = -1;
	}
};

#endif

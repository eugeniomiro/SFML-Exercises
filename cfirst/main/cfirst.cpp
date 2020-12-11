#include <iostream>
#include <SFML/Graphics.hpp>
#include "config.h"

int main(int argc, char** argv)
{
	std::cout << "cfirst version " << cfirst_VERSION_MAJOR <<
		                   "." << cfirst_VERSION_MINOR << std::endl;
	sf::RenderWindow screen(sf::VideoMode(800, 600), "cfirst");

	while(screen.isOpen())
	{
		sf::Event event;
		while (screen.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				screen.close();
		}
		screen.clear();
		screen.display();
	}

	return 0;
}

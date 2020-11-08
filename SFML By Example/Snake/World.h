#ifndef WORLD_H
#define WORLD_H
#include "Snake.h"

class World
{
	public:
		World(sf::Vector2u windowSize);
		~World();

		int GetBlockSize();

		void RespawnApple();

		void Update(Snake& player);
		void Render(sf::RenderWindow& window);

	private:
		sf::Vector2u _windowSize;
		sf::Vector2i _item;
		int _blockSize;

		sf::CircleShape _appleShape;
		sf::RectangleShape _bounds[4];
};
#endif

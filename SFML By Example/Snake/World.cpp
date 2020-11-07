#include "World.h"

World::World(sf::Vector2u windowSize)
{
	_blockSize = 16;

	_windowSize = windowSize;
	RespawnApple();
	_appleShape.setFillColor(sf::Color::Red);
	_appleShape.setRadius(_blockSize / 2);

	for (int i = 0; i < 4; ++i)
	{
		_bounds[i].setFillColor(sf::Color(150, 0, 0));
		if (!((i + 1) % 2))
	       	{
			_bounds[i].setSize(sf::Vector2f(_windowSize.x, _blockSize));
		}
		else
		{
			_bounds[i].setSize(sf::Vector2f(_blockSize, _windowSize.y));
		}

		if (i < 2) 
		{
			_bounds[i].setPosition(0, 0);
		}
		else
		{
			_bounds[i].setOrigin(_bounds[i].getSize());
			_bounds[i].setPosition(sf::Vector2f(_windowSize));
		}
	}
}

World::~World() {}

void World::RespawnApple()
{
	int maxX = (_windowSize.x / _blockSize) - 2;
	int maxY = (_windowSize.y / _blockSize) - 2;
	_item = sf::Vector2i(rand() % maxX + 1, rand() % maxY + 1);
	_appleShape.setPosition(_item.x * _blockSize, _item.y * _blockSize);
}

void World::Update(Snake& player)
{
	if (player.GetPosition() == _item)
	{
		player.Extend();
		player.IncreaseScore();
		RespawnApple();
	}
	int gridSize_x = _windowSize.x / _blockSize;
	int gridSize_y = _windowSize.y / _blockSize;

	if (player.GetPosition().x <= 0 ||
	    player.GetPosition().y <= 0 ||
	    player.GetPosition().x >= gridSize_x - 1 ||
	    player.GetPosition().y >= gridSize_y - 1)
	{
		player.Lose();
	}
}

void World::Render(sf::RenderWindow& window)
{
	for (int i = 0; i < 4; ++i)
	{
		window.draw(_bounds[i]);
	}
	window.draw(_appleShape);
}

int World::GetBlockSize() { return _blockSize; }

#include "World.h"
#include "Snake.h"
#include "Game.h"

Game::Game()
	: _window("Snake", sf::Vector2u(800, 600)),
          _world(sf::Vector2u(800, 600)),
          _snake(_world.GetBlockSize())
{
	// Setting up class members.
	_increment = sf::Vector2i(400, 400);
}

Game::~Game() { }

void Game::Update()
{
	_window.Update(); // Update window events.
	float timestep = 1.0f / _snake.GetSpeed();

	if (_elapsed >= timestep)
	{
		_snake.Tick();
		_world.Update(_snake);
		_elapsed -= timestep;
		if (_snake.HasLost())
		{
			_snake.Reset();
		}
	}
}

void Game::Render()
{
	_window.BeginDraw();	// Clear
	_world.Render(*_window.GetRenderWindow());
	_snake.Render(*_window.GetRenderWindow());
	_window.EndDraw();	// Display
}

void Game::HandleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
            _snake.GetDirection() != Direction::Down)
	{
		_snake.SetDirection(Direction::Up);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
                 _snake.GetDirection() != Direction::Up)
	{
		_snake.SetDirection(Direction::Down);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) &&
                 _snake.GetDirection() != Direction::Right)
	{
		_snake.SetDirection(Direction::Left);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) &&
                 _snake.GetDirection() != Direction::Left)
	{
		_snake.SetDirection(Direction::Right);
	}
}

Window* Game::GetWindow() { return &_window; }

void Game::RestartClock() { _elapsed += _clock.restart().asSeconds(); }


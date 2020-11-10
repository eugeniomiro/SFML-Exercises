#include "Game.h"

Game::Game()
	: _window("Snake", sf::Vector2u(800, 600)),
          _world(sf::Vector2u(800, 600)),
          _snake(_world.GetBlockSize()),
	  _textbox(5, 14, 350, sf::Vector2f(255, 0))
{
	// Setting up class members.
	_increment = sf::Vector2i(400, 400);

	_textbox.Add("Seeded random number generator with: " + std::to_string(time(NULL)));	
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
			_textbox.Add("GAME OVER. Score = " + std::to_string(_snake.GetScore()));
			_snake.Reset();
		}
	}
}

void Game::Render()
{
	_window.BeginDraw();	// Clear
	_world.Render(*_window.GetRenderWindow());
	_snake.Render(*_window.GetRenderWindow());
	_textbox.Render(*_window.GetRenderWindow());
	_window.EndDraw();	// Display
}

void Game::HandleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
            _snake.GetPhysicalDirection() != Direction::Down)
	{
		_snake.SetDirection(Direction::Up);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
                 _snake.GetPhysicalDirection() != Direction::Up)
	{
		_snake.SetDirection(Direction::Down);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) &&
                 _snake.GetPhysicalDirection() != Direction::Right)
	{
		_snake.SetDirection(Direction::Left);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) &&
                 _snake.GetPhysicalDirection() != Direction::Left)
	{
		_snake.SetDirection(Direction::Right);
	}
}

Window* Game::GetWindow() { return &_window; }

void Game::RestartClock() { _elapsed += _clock.restart().asSeconds(); }


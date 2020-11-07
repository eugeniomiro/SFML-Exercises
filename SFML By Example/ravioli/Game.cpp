#include "Game.hpp"

Game::Game() : _window("Chapter 2", sf::Vector2u(800, 600))
{
	// Setting up class members.
	_mushroomTexture.loadFromFile("Mushroom.png");
	_mushroom.setTexture(_mushroomTexture);
	_increment = sf::Vector2i(4, 4);
}

Game::~Game() { }

void Game::Update()
{
	_window.Update(); // Update window events.
	MoveMushroom();
}

void Game::MoveMushroom()
{
	sf::Vector2u windowSize = _window.GetWindowSize();
	sf::Vector2u textureSize = _mushroomTexture.getSize();

	if ((_mushroom.getPosition().x > windowSize.x - textureSize.x && _increment.x > 0) ||
	    (_mushroom.getPosition().x < 0 && _increment.x < 0)) 
	{
		_increment.x = -_increment.x;
	}
	if ((_mushroom.getPosition().y > windowSize.y - textureSize.y && _increment.y > 0) ||
	    (_mushroom.getPosition().y < 0 && _increment.y < 0)) 
	{
		_increment.y = -_increment.y;
	}

	_mushroom.setPosition(
		_mushroom.getPosition().x + _increment.x,
		_mushroom.getPosition().y + _increment.y);
}

void Game::Render()
{
	_window.BeginDraw();	// Clear
	_window.Draw(_mushroom);
	_window.EndDraw();	// Display
}

void Game::HandleInput()
{

}

Window* Game::GetWindow() { return &_window; }

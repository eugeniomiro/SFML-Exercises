#include "Window.hpp"

class Game
{
	public:
		Game();
		~Game();

		void HandleInput();
		void Update();
		void Render();
		Window* GetWindow();
		sf::Time GetElapsed();
		void RestartClock();

	private:
		void MoveMushroom();
		Window _window;
		sf::Texture  _mushroomTexture;
		sf::Sprite   _mushroom;
		sf::Vector2i _increment;
		sf::Clock    _clock;
		sf::Time     _elapsed;
};


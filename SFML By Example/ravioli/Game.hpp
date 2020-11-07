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

	private:
		void MoveMushroom();
		Window _window;
		sf::Texture  _mushroomTexture;
		sf::Sprite   _mushroom;
		sf::Vector2i _increment;
};


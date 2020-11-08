#include "Window.h"
#include "World.h"
#include "Snake.h"
#include "Textbox.h"

class Game
{
	public:
		Game();
		~Game();

		void HandleInput();
		void Update();
		void Render();
		Window* GetWindow();
		void RestartClock();

		World        _world;
		Snake        _snake;

	private:
		Window       _window;
		sf::Vector2i _increment;
		sf::Clock    _clock;
		float        _elapsed;
		Textbox      _textbox;
};


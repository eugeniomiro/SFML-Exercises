#include "Game.hpp"

int main(int argc, char* argv[])
{
	// Program entry point.
	Game game;

	while(!game.GetWindow()->IsDone())
	{
		// Game loop.
		game.HandleInput();
		game.Update();
		game.Render();
	}

	return 0;
}

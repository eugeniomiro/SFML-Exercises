#include "Snake.h"
#include "World.h"
#include "Game.h"

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
		game.RestartClock();
	}

	return 0;
}

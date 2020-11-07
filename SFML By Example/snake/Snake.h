#ifndef SNAKE_H
#define SNAKE_H
#include <SFML/Graphics.hpp>
#include <vector>

struct SnakeSegment
{
	SnakeSegment(int x, int y) : position(x, y) {}
	sf::Vector2i position;
};

using SnakeContainer = std::vector<SnakeSegment>;

enum class Direction { None, Up, Down, Left, Right };

class Snake
{
	public:
		Snake(int blockSize);
		~Snake();

		// Helper methods.
		void SetDirection(Direction dir);
		Direction GetDirection();
		int GetSpeed();
		sf::Vector2i GetPosition();
		int GetLives();
		int GetScore();
		void IncreaseScore();
		bool HasLost();

		void Lose();	// Handle losing here
		void ToggleLost();

		void Extend();	// Grow the snake
		void Reset();	// Reset to the starting position

		void Move();	// Movement method.
		void Tick();	// Update method.
		void Cut(int segments);	// Method for cutting the snake.
		void Render(sf::RenderWindow& window);

	private:
		void CheckCollision();
		SnakeContainer _snakeBody;
		int _size;			// Size of the graphics
		Direction _dir;			// Current direction
		int _speed;
		int _lives;
		int _score;
		bool _lost;			// Losing state.
		sf::RectangleShape _bodyRect;	// shape used in rendering
};
#endif

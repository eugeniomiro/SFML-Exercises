#include "Snake.h"

Snake::Snake(int blockSize)
{
	_size = blockSize;
	_bodyRect.setSize(sf::Vector2f(_size - 1, _size - 1));
	Reset();
}

Snake::~Snake() { }

void Snake::Reset()
{
	_snakeBody.clear();

	_snakeBody.push_back(SnakeSegment(5, 7));
	_snakeBody.push_back(SnakeSegment(5, 6));
	_snakeBody.push_back(SnakeSegment(5, 5));

	SetDirection(Direction::None);	// Start off still.

	_speed = 15;
	_lives = 3;
	_score = 0;
	_lost = false;
}

void Snake::SetDirection(Direction direction) { _dir = direction; }

Direction Snake::GetDirection() { return _dir; }

int Snake::GetSpeed() { return _speed; }

sf::Vector2i Snake::GetPosition()
{
	return (!_snakeBody.empty() ? _snakeBody.front().position : sf::Vector2i(1, 1));
}

int Snake::GetLives() { return _lives; }

int Snake::GetScore() { return _score; }

void Snake::IncreaseScore() { _score += 10; }

bool Snake::HasLost() { return _lost; }

void Snake::Lose() { _lost = true; }

void Snake::ToggleLost() { _lost = !_lost; }

void Snake::Extend()
{
	if (_snakeBody.empty()) { return; }
	SnakeSegment& tail_head = _snakeBody[_snakeBody.size() - 1];

	if (_snakeBody.size() > 1)
	{
		SnakeSegment& tail_bone = _snakeBody[_snakeBody.size() - 2];
		if (tail_head.position.x == tail_bone.position.x)
		{
			if (tail_head.position.y > tail_bone.position.y)
			{
				_snakeBody.push_back(SnakeSegment(tail_head.position.x,
								  tail_head.position.y + 1));
			} else {
				_snakeBody.push_back(SnakeSegment(tail_head.position.x,
								  tail_head.position.y - 1));
			}
		}
	       	else if (tail_head.position.y == tail_bone.position.y)
		{
			if (tail_head.position.x > tail_head.position.x)
			{
				_snakeBody.push_back(SnakeSegment(tail_head.position.x + 1,
								  tail_head.position.y));
			}
			else
			{
				_snakeBody.push_back(SnakeSegment(tail_head.position.x - 1,
								  tail_head.position.y));

			}
		}
		else
		{
			if (_dir == Direction::Up)
			{
				_snakeBody.push_back(SnakeSegment(tail_head.position.x,
								  tail_head.position.y + 1));

			}
			else if (_dir == Direction::Down)
			{
				_snakeBody.push_back(SnakeSegment(tail_head.position.x,
								  tail_head.position.y - 1));
			}
			else if (_dir == Direction::Left)
			{
				_snakeBody.push_back(SnakeSegment(tail_head.position.x + 1,
								  tail_head.position.y));
			}
			else if (_dir == Direction::Right)
			{
				_snakeBody.push_back(SnakeSegment(tail_head.position.x - 1,
								  tail_head.position.y));
			}
		}
	}
}

void Snake::Tick()
{
	if (_snakeBody.empty()) { return; }
	if (_dir == Direction::None) { return; }
	Move();
	CheckCollision();
}

void Snake::Move()
{
	for(int i = _snakeBody.size() - 1; i > 0; --i)
	{
		_snakeBody[i].position = _snakeBody[i - 1].position;
	}
	if (_dir == Direction::Left)
       	{
		--_snakeBody[0].position.x;
	}
	else if (_dir == Direction::Right)
	{
		++_snakeBody[0].position.x;
	}
	else if (_dir == Direction::Up)
	{
		--_snakeBody[0].position.y;
	}
	else if (_dir == Direction::Down)
	{
		++_snakeBody[0].position.y;
	}
}

void Snake::CheckCollision()
{
	if (_snakeBody.size() < 5) { return; }
	SnakeSegment& head = _snakeBody.front();
	for (auto itr = _snakeBody.begin() + 1; itr != _snakeBody.end(); ++itr)
	{
		if (itr->position == head.position)
		{
			int segments = _snakeBody.end() - itr;
			Cut(segments);
			break;
		}
	}
}

void Snake::Cut(int segments)
{
	for (int i = 0; i < segments; ++i)
	{
		_snakeBody.pop_back();
	}
	--_lives;
	if (!_lives) { Lose(); }
}

void Snake::Render(sf::RenderWindow& window)
{
	if (_snakeBody.empty()) { return; }

	auto head = _snakeBody.begin();
	_bodyRect.setFillColor(sf::Color::Yellow);
	_bodyRect.setPosition(head->position.x * _size, head->position.y * _size);
	window.draw(_bodyRect);

	_bodyRect.setFillColor(sf::Color::Green);
	for (auto itr = _snakeBody.begin() + 1; itr != _snakeBody.end(); ++itr)
	{
		_bodyRect.setPosition(itr->position.x * _size, itr->position.y * _size);
		window.draw(_bodyRect);
	}
}


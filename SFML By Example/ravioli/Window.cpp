#include "Window.hpp"

Window::Window() { Setup("Window", sf::Vector2u(640, 480)); }

Window::Window(const std::string& title, const sf::Vector2u& size)
{
	Setup(title, size);
}

Window::~Window() { Destroy(); }

void Window::Setup(const std::string& title, const sf::Vector2u& size)
{
	_windowTitle = title;
	_windowSize = size;
	_isFullscreen = false;
	_isDone = false;
	Create();
}

void Window::Create()
{
	auto style = (_isFullscreen ? sf::Style::Fullscreen : sf::Style::Default);
	_window.create({ _windowSize.x, _windowSize.y, 32 }, _windowTitle, style);
}

void Window::Destroy()
{
	_window.close();
}

void Window::Update()
{
	sf::Event event;
	while (_window.pollEvent(event))
       	{
		if (event.type == sf::Event::Closed)
		{
			_isDone = true;
		}
		else if (event.type == sf::Event::KeyPressed &&
			 event.key.code == sf::Keyboard::F5)
		{
			ToggleFullscreen();
		}
	}
}

void Window::ToggleFullscreen()
{
	_isFullscreen = !_isFullscreen;
	Destroy();
	Create();	
}

void Window::BeginDraw() { _window.clear(sf::Color::Black); }

void Window::EndDraw() { _window.display(); }

bool Window::IsDone() { return _isDone; }

bool Window::IsFullScreen() { return _isFullscreen; }

sf::Vector2u Window::GetWindowSize() { return _windowSize; }

void Window::Draw(sf::Drawable& drawable)
{
	_window.draw(drawable);
}



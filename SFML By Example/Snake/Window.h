#include <string>
#include <SFML/Graphics.hpp>

class Window
{
	public:
		Window();
		Window(const std::string& title, const sf::Vector2u& size);
		~Window();

		void BeginDraw();
		void EndDraw();

		void Update();

		bool IsDone();
		bool IsFullScreen();
		sf::Vector2u GetWindowSize();

		void ToggleFullscreen();

		void Draw(sf::Drawable& drawable);
		sf::RenderWindow* GetRenderWindow();

	private:
		void Setup(const std::string& title, const sf::Vector2u& size);
		void Destroy();
		void Create();

		sf::RenderWindow _window;
		sf::Vector2u     _windowSize;
		std::string      _windowTitle;
		bool             _isDone;
		bool             _isFullscreen;
};

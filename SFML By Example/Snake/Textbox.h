#ifndef TEXTBOX_H
#define TEXTBOX_H
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

using MessageContainer = std::vector<std::string>;

class Textbox
{
	public:
		Textbox();
		Textbox(int visible, int charSize, int width, sf::Vector2f screenPos);
		~Textbox();

		void Setup(int visible, int charSize, int width, sf::Vector2f screenPos);
		void Add(std::string message);
		void Clear();

		void Render(sf::RenderWindow& window);
	private:
		MessageContainer _messages;
		int _numVisible;

		sf::RectangleShape _backdrop;
		sf::Font _font;
		sf::Text _content;
};

#endif

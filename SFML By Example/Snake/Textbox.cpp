#include "Textbox.h"

Textbox::Textbox()
{
	Setup(5, 9, 200, sf::Vector2f(0, 0));
}

Textbox::Textbox(int visible, int charSize, int width, sf::Vector2f screenPos)
{
	Setup(visible, charSize, width, screenPos);
}

Textbox::~Textbox() { Clear(); }

void Textbox::Setup(int visible, int charSize, int width, sf::Vector2f screenPos)
{
	_numVisible = visible;

	sf::Vector2f offset(2.0f, 2.0f);

	_font.loadFromFile("arial.ttf");
	_content.setFont(_font);
	_content.setString("");
	_content.setCharacterSize(charSize);
	_content.setColor(sf::Color::White);
	_content.setPosition(screenPos + offset);

	_backdrop.setSize(sf::Vector2f(width, (visible * (charSize * 1.2f))));
	_backdrop.setFillColor(sf::Color(90, 90, 90, 90));
	_backdrop.setPosition(screenPos);
}

void Textbox::Add(std::string message)
{
	_messages.push_back(message);
	if (_messages.size() < 6) { return; }
	_messages.erase(_messages.begin());
}

void Textbox::Clear() { _messages.clear(); }

void Textbox::Render(sf::RenderWindow& window)
{
	std::string content;

	for (auto &itr: _messages)
	{
		content.append(itr + "\n");
	}

	if (content != "")
	{
		_content.setString(content);
		window.draw(_backdrop);
		window.draw(_content);
	}
}


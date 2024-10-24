#include "Button.hpp"

Button::Button(Scene& parentScene, std::string identifier, sf::Font& font, std::string buttonText, sf::Vector2f size, sf::Color color)
	: GameObject(parentScene, identifier), font(font), buttonText(buttonText)
{
	shape.setSize(size);
	shape.setFillColor(color);

	text.setFont(font);
	text.setString(buttonText);
}

Button::~Button(){ }

bool Button::isClicked()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
		sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
		sf::Vector2f size = shape.getSize();
		sf::Vector2f position = shape.getPosition();

		if (mousePosition.x >= position.x && mousePosition.x <= position.x + size.x &&
			mousePosition.y >= position.y && mousePosition.y <= position.y + size.y) {
			return true;
		}
	}

	return false;
}

void Button::update(){
	if (isClicked() && action) {
		action();
	}
}

void Button::render(){
	window.draw(shape);
}

void Button::setButtonAction(std::function<void()> action)
{
	this->action = action;
}

void Button::setCharacterSize(const int size)
{
	text.setCharacterSize(size);
}

void Button::setPosition(const sf::Vector2f position)
{
	GameObject::setPosition(position);
	shape.setPosition(position);
	text.setPosition(position);
}

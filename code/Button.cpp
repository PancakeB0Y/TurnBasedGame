#include "Button.hpp"
#include <iostream>

Button::Button(Scene& parentScene, std::string identifier, sf::Font& font, std::string buttonText, sf::Vector2f size, int characterSize, sf::Color color, sf::Color textColor)
	: GameObject(parentScene, identifier), font(font), buttonText(buttonText), fillColor(color)
{

	shape.setSize(size);
	shape.setFillColor(color);

	text.setCharacterSize(characterSize);
	text.setFont(font);
	text.setString(buttonText);
	text.setFillColor(textColor);

	text.setOrigin(sf::Vector2f((text.getLocalBounds().width / 2), text.getLocalBounds().height / 2));
	text.setPosition(sf::Vector2f(shape.getPosition().x + (shape.getSize().x / 2) + text.getLocalBounds().left, shape.getPosition().y + (shape.getSize().y / 2) - text.getLocalBounds().top));
}

Button::~Button(){ }

void Button::handleEvent(const sf::Event& event)
{
	if (!enabled) {
		return;
	}

	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Button::Left) {
		sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
		sf::Vector2f size = shape.getSize();
		sf::Vector2f position = shape.getPosition();

		if (mousePosition.x >= position.x && mousePosition.x <= position.x + size.x &&
			mousePosition.y >= position.y && mousePosition.y <= position.y + size.y) {
			action();
		}
	}
}

void Button::update(){
	if (!enabled) {
		shape.setFillColor(sf::Color::Black);
	}
	else {
		shape.setFillColor(fillColor);
	}
}

void Button::render(){
	window.draw(shape);
	window.draw(text);
}

sf::RectangleShape Button::getShape() const { return this->shape; }

void Button::setButtonAction(std::function<void()> action)
{
	this->action = action;
}

void Button::setCharacterSize(const int size)
{
	text.setCharacterSize(size);
}

void Button::setPosition(const int x, const int y)
{
	sf::Vector2f position(x, y);
	GameObject::setPosition(sf::Vector2f(position));
	shape.setPosition(position);
	text.setPosition(sf::Vector2f(shape.getPosition().x + (shape.getSize().x / 2) + text.getLocalBounds().left, shape.getPosition().y + (shape.getSize().y / 2) - text.getLocalBounds().top));
}

void Button::setPosition(sf::Vector2f position)
{
	GameObject::setPosition(sf::Vector2f(position));
	shape.setPosition(position);
	text.setPosition(sf::Vector2f(shape.getPosition().x + (shape.getSize().x / 2) + text.getLocalBounds().left, shape.getPosition().y + (shape.getSize().y / 2) - text.getLocalBounds().top));
}

void Button::setEnable(const bool enabled)
{
	this->enabled = enabled;
}

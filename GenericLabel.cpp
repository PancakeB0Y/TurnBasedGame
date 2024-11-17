#include "GenericLabel.hpp"

GenericLabel::GenericLabel(Scene& parentScene, std::string identifier, sf::Font& font, std::string textString, int characterSize, sf::Color textColor, sf::Vector2f textPosition) : GameObject(parentScene, identifier), font(font)
{
	text.setFont(font);
	text.setString(textString);
	text.setCharacterSize(characterSize);
	text.setFillColor(textColor);
	text.setPosition(textPosition);
}

sf::Text GenericLabel::getText() const { return this->text; }

void GenericLabel::setText(std::string text)
{
	this->text.setString(text);
}

void GenericLabel::update(){ }

void GenericLabel::render()
{
	window.draw(text);
}

void GenericLabel::setPosition(sf::Vector2f position)
{
	GameObject::setPosition(position);
	text.setPosition(text.getPosition() + position);
}



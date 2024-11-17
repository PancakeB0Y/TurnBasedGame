#include "RectangleObject.hpp"

RectangleObject::RectangleObject(Scene& parentScene, std::string identifier, sf::Vector2f position, sf::Vector2f size, sf::Color color)
	: GameObject(parentScene, identifier, position)
{
	shape.setSize(size);
	shape.setFillColor(color);
	shape.setPosition(position);
}

RectangleObject::~RectangleObject() {};

void RectangleObject::update() {}

void RectangleObject::render() {
	window.draw(shape);
}

sf::RectangleShape RectangleObject::getShape() const
{
	return this->shape;
}

void RectangleObject::setColor(const sf::Color color)
{
	this->shape.setFillColor(color);
}

void RectangleObject::setPosition(const int x, const int y)
{
	sf::Vector2f position(x, y);
	GameObject::setPosition(sf::Vector2f(position));
	shape.setPosition(position);
}

void RectangleObject::setPosition(sf::Vector2f position)
{
	GameObject::setPosition(sf::Vector2f(position));
	shape.setPosition(position);
}
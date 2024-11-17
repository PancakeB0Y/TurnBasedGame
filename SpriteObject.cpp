#include <iostream>
#include "SpriteObject.hpp"

SpriteObject::SpriteObject(Scene& parentScene, std::string identifier, std::string spriteFile) : GameObject(parentScene, identifier), spriteFile(spriteFile){
	if (!texture.loadFromFile(spriteFile)) {
		std::cout << "Failed to load texture of sprite object \"" + identifier + "\"";
	}
	sprite.setTexture(texture);
	sprite.setOrigin(sf::Vector2f(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2));
}

SpriteObject::~SpriteObject(){}

void SpriteObject::update() {}
void SpriteObject::render() {
	window.draw(sprite);
}

std::string SpriteObject::getSpriteFile() const {
	return this->spriteFile;
}

void SpriteObject::setPosition(const sf::Vector2f position) {
	this->position = position;
	sprite.setPosition(position);
}

void SpriteObject::setPosition(const float x, const float y) {
	sf::Vector2f position(x, y);
	this->position = position;
	sprite.setPosition(position);
}

void SpriteObject::setScale(const sf::Vector2f scale) {
	sprite.setScale(scale);
}

void SpriteObject::setScale(const float width, const float height) {
	sf::Vector2f scale(width, height);
	sprite.setScale(scale);
}


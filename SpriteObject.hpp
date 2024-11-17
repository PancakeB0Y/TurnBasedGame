#pragma once

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "GameObject.hpp";

class SpriteObject : public GameObject{
	private:
		std::string spriteFile;
		sf::Sprite sprite;
		sf::Texture texture;
	public:
		SpriteObject(Scene& parentScene, std::string identifier, std::string spriteFile);
		~SpriteObject();

		void update() override;
		void render() override;

		std::string getSpriteFile() const;
		sf::Sprite getSprite() const;

		void setPosition(const sf::Vector2f position);
		void setPosition(const float x, const float y);
		void setScale(const sf::Vector2f scale);
		void setScale(const float x, const float y);

};


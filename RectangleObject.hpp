#pragma once

#include <SFML/Graphics/RectangleShape.hpp>

#include "GameObject.hpp";

class RectangleObject : public GameObject
{
	private:
		sf::RectangleShape shape;
	public:
		RectangleObject(Scene& parentScene, std::string identifier, sf::Vector2f position = sf::Vector2f(0, 0), sf::Vector2f size = sf::Vector2f(0, 0),sf::Color color = sf::Color::White);
		~RectangleObject();

		void update() override;
		void render() override;

		sf::RectangleShape getShape() const;

		void setColor(const sf::Color color);
		void setPosition(const int x, const int y);
		void setPosition(const sf::Vector2f position);
		
};


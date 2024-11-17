#pragma once

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>

#include "GameObject.hpp";

class GenericLabel : public GameObject
{
	protected:
		sf::Text text;
		sf::Font& font;

	public:
		GenericLabel(Scene& parentScene, std::string identifier, sf::Font& font, std::string textString = "", int characterSize = 24, sf::Color textColor = sf::Color::White, sf::Vector2f textPosition = sf::Vector2f(0, 0));

		virtual void update() override;
		virtual void render() override;

		sf::Text getText() const;
		void setText(const std::string text);
		void setTextColor(const sf::Color textColor);
		virtual void setPosition(const sf::Vector2f position) override;

};


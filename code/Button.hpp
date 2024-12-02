#pragma once

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/Mouse.hpp>
#include <functional>

#include "GameObject.hpp";

class Button : public GameObject
{
	private:
		sf::Text text;
		sf::Font& font;
		sf::RectangleShape shape;
		std::string buttonText;
		std::function<void()> action;
		sf::Color fillColor;
		bool enabled = true;

	public:
		Button(Scene& parentScene, std::string identifier, sf::Font& font, std::string buttonText = "", sf::Vector2f size = sf::Vector2f(0, 0), int characterSize = 24, sf::Color color = sf::Color::White, sf::Color textColor = sf::Color::Black);
		~Button();

		void handleEvent(const sf::Event& event) override;

		void update() override;
		void render() override;

		sf::RectangleShape getShape() const;

		void setButtonAction(const std::function<void()> action);
		void setCharacterSize(const int size);
		void setPosition(const int x, const int y);
		void setPosition(const sf::Vector2f position);
		void setEnable(const bool enabled);
};


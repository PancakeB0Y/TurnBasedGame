#pragma once

#include <SFML/Graphics.hpp>

#include "GenericLabel.hpp";

class FPSCounter : public GenericLabel {
	public:
		FPSCounter(Scene& parentScene, std::string identifier, sf::Font font, std::string textString = "", int characterSize = 24, sf::Color textColor = sf::Color::Green, sf::Vector2f textPosition = sf::Vector2f(0, 0));
		~FPSCounter() override;
		void update(sf::Time elapsed);
		void render() override;
};
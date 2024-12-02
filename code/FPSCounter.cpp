#include "FPSCounter.hpp";

FPSCounter::FPSCounter(Scene& parentScene, std::string identifier, sf::Font font, std::string textString, int characterSize, sf::Color textColor, sf::Vector2f textPosition)
: GenericLabel(parentScene, identifier, font, textString, characterSize, textColor, textPosition)
{
	text.setString("FPS: ");
}

FPSCounter::~FPSCounter() { }

void FPSCounter::update(sf::Time elapsed) {
	float second = elapsed.asSeconds();
	float fps = 1.0f / (second != 0 ? second : 0.01665f);
	text.setString("FPS: " + std::to_string(fps));
}

void FPSCounter::render() {
	window.draw(text);
}
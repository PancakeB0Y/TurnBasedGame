#include <SFML/Graphics.hpp>
#include <iostream>

#include "Scene.hpp"
#include "FPSCounter.hpp"
#include "Button.hpp"

int main() {
    sf::Font font;
    font.loadFromFile("assets/fonts/Roboto-Regular.ttf");

    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
    Scene scene("scene01", window);

    GenericLabel label1(scene, "label1", font, "label1", 24, sf::Color::Green, sf::Vector2f(0, 24));
    GenericLabel label2(scene, "label2", font, "label2", 24, sf::Color::Red, sf::Vector2f(0, 48));
    label2.setParent(&label1);
    GenericLabel label3(scene, "label3", font, "label3", 24, sf::Color::Cyan, sf::Vector2f(0, 72));
    label3.setParent(&label2);

    Button testButton(scene, "testButton", font, "Click Me", sf::Vector2f(20, 20), sf::Color::Red);

    std::function<void()> printText;
    printText = []() {std::cout << "button pressed";};

    testButton.setButtonAction(printText);
    
    while (window.isOpen()) {   
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        scene.update();
        scene.render();
        window.display();
    }

    return 0;
}
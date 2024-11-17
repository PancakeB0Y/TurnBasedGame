#include <SFML/Graphics.hpp>
#include <iostream>

#include "Scene.hpp"
#include "GenericLabel.hpp"
#include "Button.hpp"
#include "Character.hpp"
#include "SpriteObject.hpp"

int main() {
    sf::Font font;
    font.loadFromFile("assets/fonts/Roboto-Regular.ttf");

    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
    Scene *curScene;

    Scene startScene("scene01", window);

    Scene gameScene("scene02", window);

    //Start scene objects
    Button startButton(startScene, "startButton", font, "Start", sf::Vector2f(100, 50));
    startButton.setCharacterSize(20);
    const sf::Vector2f &buttonSize = startButton.getShape().getLocalBounds().getSize();
    startButton.setPosition(window.getView().getCenter() - sf::Vector2f(buttonSize.x / 2, buttonSize.y / 2));

    std::function<void()> changeScene;
    changeScene = [&curScene, &gameScene, &startScene]() {
        curScene = &gameScene;
     };

    startButton.setButtonAction(changeScene);
    
    //Game scene objects
    GenericLabel labelGame(gameScene, "label1", font, "The Mighty Player", 24, sf::Color::White, sf::Vector2f(0, 24));
    
    Character player("player", "assets/images/el-gato.png");
    SpriteObject characterAvatar(gameScene, "playerSprite", player.getSpriteFile());
    characterAvatar.setPosition(window.getView().getCenter());
    characterAvatar.setScale(0.5f, 0.5f);

    //curScene = &startScene;
    curScene = &gameScene;

    while (window.isOpen()) {   
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        if (curScene != NULL) {
            curScene->update();
            curScene->render();
        }

        window.display();
    }

    return 0;
}
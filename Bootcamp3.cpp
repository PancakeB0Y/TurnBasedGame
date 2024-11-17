#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <iostream>

#include "Scene.hpp"
#include "GenericLabel.hpp"
#include "Button.hpp"
#include "Character.hpp"
#include "SpriteObject.hpp"
#include "RectangleObject.hpp"

void enablePlayerAction(Button &attackButton, Button &healButton, Button &doNothingButton, bool &playerTurnInProgress) {
    attackButton.setEnable(true);
    healButton.setEnable(true);
    doNothingButton.setEnable(true);
    playerTurnInProgress = true;
}

void disablePlayerAction(Button& attackButton, Button& healButton, Button& doNothingButton, bool &playerTurnInProgress) {
    attackButton.setEnable(false);
    healButton.setEnable(false);
    doNothingButton.setEnable(false);
    playerTurnInProgress = false;
}

void handleEnemyAction(Character& player, Character& enemy, GenericLabel& enemyTurnInfo) {
    int enemyChoice = rand() % 3;
    
    if (enemyChoice == 0) {
        int damageDealt = enemy.attackOpponent(player);
        enemyTurnInfo.setText(std::string("Enemy dealt ") + std::to_string(damageDealt) + " damage to you");
    }
    else if (enemyChoice == 1) {
        int healAmount = enemy.heal();
        enemyTurnInfo.setText(std::string("Enemy healed for ") + std::to_string(healAmount));
    }
    else if (enemyChoice == 2) {
        enemyTurnInfo.setText("Enemy chose to do nothing...");
    }
}

int* getRandEnemyStats(const int curEnemyCount, const float difficultyMult) {
    // Randomize enemy stats
    float mult = 1 + curEnemyCount * difficultyMult;
    float totalStats = 4.0f * mult + curEnemyCount + 4;

    int randHealth = rand() % (int)(totalStats - 3) + 1;
    totalStats -= randHealth;

    int randAttack = rand() % (int)(totalStats - 2) + 1;
    totalStats -= randAttack;

    int randDefense = rand() % (int)(totalStats - 1) + 1;
    totalStats -= randDefense;

    int randAgility = (int)totalStats;

    int randStats[4] = { randHealth, randAttack, randDefense, randAgility };

    return randStats;
}

void handleEnemyDeath(Character &enemy, int &curEnemyCount, const float &difficultyMult, GenericLabel& enemyTurnInfo, RectangleObject &enemyTint) {
    enemyTurnInfo.setText("Enemy died. A new enemy emerged");
    curEnemyCount++;

    int* randEnemyStats = getRandEnemyStats(curEnemyCount, difficultyMult);
    enemy.setStats(randEnemyStats[0], randEnemyStats[1], randEnemyStats[2], randEnemyStats[3]);

    enemyTint.setColor(sf::Color(rand() % 256, rand() % 256, rand() % 256, 127));
}

void updateStats(GenericLabel& playerStats, Character& player, GenericLabel& enemyStats, Character& enemy) {
    playerStats.setText("Health: " + std::to_string(player.getHealth()) + "\nAttack: " + std::to_string(player.getAttack())
        + "\nAgility: " + std::to_string(player.getAgility()) + "\nDefense: " + std::to_string(player.getDefense()));

    enemyStats.setText("Health: " + std::to_string(enemy.getHealth()) + "\nAttack: " + std::to_string(enemy.getAttack())
        + "\nAgility: " + std::to_string(enemy.getAgility()) + "\nDefense: " + std::to_string(enemy.getDefense()));
}

void updateCounters(GenericLabel &turnCountDisplay, int &turnCount, GenericLabel &enemyDefeatedCountDisplay, int &enemyDefeatedCount) {
    turnCountDisplay.setText("Turn: " + std::to_string(turnCount));
    enemyDefeatedCountDisplay.setText("Enemies defeated: " + std::to_string(enemyDefeatedCount));
}

int main() {
    sf::Font font;
    font.loadFromFile("assets/fonts/Roboto-Regular.ttf");

    sf::Vector2f windowSize(1280, 720);
    sf::RenderWindow window(sf::VideoMode(windowSize.x, windowSize.y), "SFML works!");
    Scene *curScene;

    Scene startScene("scene01", window);

    Scene gameScene("scene02", window);

    bool turnInProgress = false;
    bool playerTurnInProgress = true;

    //Start scene objects
    Button startButton(startScene, "startButton", font, "Start", sf::Vector2f(100, 50), 20);
    const sf::Vector2f &buttonSize = startButton.getShape().getSize();
    startButton.setPosition(window.getView().getCenter().x - buttonSize.x / 2, windowSize.y * 0.3f);

    std::function<void()> changeScene = [&curScene, &gameScene, &startScene]() {
        curScene = &gameScene;
     };
    startButton.setButtonAction(changeScene);

    Button eraseDataButton(startScene, "eraseDataButton", font, "Erase Game Data", sf::Vector2f(200, 50), 20);
    const sf::Vector2f& buttonSize2 = eraseDataButton.getShape().getSize();
    eraseDataButton.setPosition(window.getView().getCenter().x - buttonSize2.x / 2, windowSize.y * 0.4f);

    std::function<void()> eraseData = []() {
        ///
        ///TODO: ERASE GAME DATA
        /// 
    };
    eraseDataButton.setButtonAction(eraseData);

    Button quitButton(startScene, "quitButton", font, "Quit", sf::Vector2f(100, 50), 20);
    quitButton.setPosition(window.getView().getCenter().x - buttonSize.x / 2, windowSize.y * 0.5f);

    std::function<void()> quitGame = []() {
        exit(0);
    };
    quitButton.setButtonAction(quitGame);
    
    //Game scene objects
    
    RectangleObject infoDisplay(gameScene, "infoDisplay", sf::Vector2f(0, windowSize.y - 200), sf::Vector2f(windowSize.x, 200));

    //Player visuals
    srand(time(NULL));
    int randPlayerIndex = rand() % 3;

    std::string playerSpriteFiles[3] = { "assets/images/el-gato.png", "assets/images/el-gato-kanye.png", "assets/images/el-gato-yeat.png" };
    std::string playerNames[3] = { "The Mighty Player", "The Studious Player", "The Daring Player" };

    Character player("player", playerSpriteFiles[randPlayerIndex], 20, 10, 3, 5);
    SpriteObject playerSprite(gameScene, "playerSprite", player.getSpriteFile());
    playerSprite.setScale(0.5f, 0.5f);
    playerSprite.setPosition(playerSprite.getSprite().getGlobalBounds().width, windowSize.y - infoDisplay.getShape().getSize().y - (playerSprite.getSprite().getGlobalBounds().height / 2) - 20);

    GenericLabel playerName(gameScene, "playerName", font, playerNames[randPlayerIndex], 24, sf::Color::White, sf::Vector2f(playerSprite.getSprite().getGlobalBounds().width / 2, windowSize.y - infoDisplay.getShape().getSize().y - (playerSprite.getSprite().getGlobalBounds().height) - 80));
    GenericLabel playerStats(gameScene, "playerStats", font, 
        "Health: " + std::to_string(player.getHealth()) + "\nAttack: " + std::to_string(player.getAttack())
        + "\nAgility: " + std::to_string(player.getAgility()) + "\nDefense: " + std::to_string(player.getDefense()), 24, sf::Color::White, sf::Vector2f(playerSprite.getPosition().x + 100, playerSprite.getPosition().y - (playerSprite.getSprite().getGlobalBounds().height / 2) + 25));


    int* randEnemyStats = getRandEnemyStats(0, 0.5f);

    //Enemy visuals
    Character enemy("enemy", "assets/images/evil-cat.jpg", randEnemyStats[0], randEnemyStats[1], randEnemyStats[2], randEnemyStats[3]);
    SpriteObject enemySprite(gameScene, "enemySprite", enemy.getSpriteFile());
    enemySprite.setScale(0.5f, 0.5f);
    enemySprite.setPosition(windowSize.x - enemySprite.getSprite().getGlobalBounds().width - 20, enemySprite.getSprite().getGlobalBounds().height);
    RectangleObject enemyTint(gameScene, "enemyTint", enemySprite.getPosition() - sf::Vector2f(enemySprite.getSprite().getGlobalBounds().width/ 2, enemySprite.getSprite().getGlobalBounds().height / 2), enemySprite.getSprite().getGlobalBounds().getSize(), sf::Color(0, 0, 0, 0));

    GenericLabel enemyName(gameScene, "enemyName", font, "The Nefarious Enemy", 24, sf::Color::White, sf::Vector2f(windowSize.x - enemySprite.getSprite().getGlobalBounds().width - 120, 20));
    GenericLabel enemyStats(gameScene, "enemyStats", font,
        "Health: " + std::to_string(enemy.getHealth()) + "\nAttack: " + std::to_string(enemy.getAttack())
        + "\nAgility: " + std::to_string(enemy.getAgility()) + "\nDefense: " + std::to_string(enemy.getDefense()), 24, sf::Color::White, sf::Vector2f(enemySprite.getPosition().x - enemySprite.getSprite().getGlobalBounds().width, enemySprite.getPosition().y - (enemySprite.getSprite().getGlobalBounds().height / 2)));

    GenericLabel turnInfo(gameScene, "turnInfo", font, "Choose an action", 24, sf::Color::Black, sf::Vector2f(infoDisplay.getPosition().x, infoDisplay.getPosition().y + 100));
    GenericLabel enemyTurnInfo(gameScene, "enemyTurnInfo", font, "..............", 24, sf::Color::Black, sf::Vector2f(infoDisplay.getPosition().x, infoDisplay.getPosition().y + 150));

    Button attackButton(gameScene, "attackButton", font, "Attack", sf::Vector2f(100, 50), 20, sf::Color::Red);
    attackButton.setPosition(infoDisplay.getPosition().x, infoDisplay.getPosition().y + 20);

    Button healButton(gameScene, "healButton", font, "Heal", sf::Vector2f(100, 50), 20, sf::Color::Green);
    healButton.setPosition(infoDisplay.getPosition().x + 120, infoDisplay.getPosition().y + 20);

    Button doNothingButton(gameScene, "doNothingButton", font, "Do nothing", sf::Vector2f(120, 50), 20, sf::Color(126, 126, 126));
    doNothingButton.setPosition(infoDisplay.getPosition().x + 240, infoDisplay.getPosition().y + 20);

    std::function<void()> attack = [&player, &enemy, &turnInfo, &attackButton, &healButton, &doNothingButton, &playerTurnInProgress]() {
        turnInfo.setText(std::string("You attacked for ") + std::to_string(player.attackOpponent(enemy)) + " damage");
        disablePlayerAction(attackButton, healButton, doNothingButton, playerTurnInProgress);
    };
    attackButton.setButtonAction(attack);

    std::function<void()> heal = [&player, &turnInfo, &attackButton, &healButton, &doNothingButton, &playerTurnInProgress]() {
        turnInfo.setText(std::string("You healed ") + std::to_string(player.heal()) + " health");
        disablePlayerAction(attackButton, healButton, doNothingButton, playerTurnInProgress);
    };
    healButton.setButtonAction(heal);

    std::function<void()> doNothing = [&turnInfo, &attackButton, &healButton, &doNothingButton, &playerTurnInProgress]() {
        turnInfo.setText("You did nothing...");
        disablePlayerAction(attackButton, healButton, doNothingButton, playerTurnInProgress);
    };
    doNothingButton.setButtonAction(doNothing);

    attackButton.setEnable(false);
    healButton.setEnable(false);
    doNothingButton.setEnable(false);


    //Difficulty multiplier for enemies
    const float difficultyMult = 0.5f;

    int enemyDefeatedCount = 0;
    int turnCount = 1;

    GenericLabel turnCountDisplay(gameScene, "turnCountDisplay", font, "Turn: " + std::to_string(turnCount), 24, sf::Color::White, sf::Vector2f(0, 0));
    GenericLabel enemyDefeatedCountDisplay(gameScene, "enemyDefeatedCountDisplay", font, "Enemies defeated: " + std::to_string(enemyDefeatedCount), 24, sf::Color::White, sf::Vector2f(0, 25));

    //curScene = &startScene;
    curScene = &gameScene;

    sf::Event event;
    while (window.isOpen()) {   
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else {
                curScene->handleEvent(event);
            }
        }
        
        window.clear();

        if (playerTurnInProgress) {
            enablePlayerAction(attackButton, healButton, doNothingButton, playerTurnInProgress);
        }
        else {
            if (enemy.isDead()) {
                handleEnemyDeath(enemy, enemyDefeatedCount, difficultyMult, enemyTurnInfo, enemyTint);
            }
            else {
                handleEnemyAction(player, enemy, enemyTurnInfo);
            }
            playerTurnInProgress = true;
            turnCount++;
        }

        if (curScene != NULL) {
            curScene->update();
            curScene->render();

            updateStats(playerStats, player, enemyStats, enemy);
            updateCounters(turnCountDisplay, turnCount, enemyDefeatedCountDisplay, enemyDefeatedCount);
        }
        window.display();
    }

    return 0;
}
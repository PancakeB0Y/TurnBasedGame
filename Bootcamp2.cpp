//#include <iostream>
//
//#include "RestartProgram.hpp"
//#include "Character.hpp"
//
//void handlePlayerAction(Character& player, Character& enemy) {
//    std::string playerInput;
//
//    do {
//        // Read player input
//        std::cin >> playerInput;
//        std::cout << "\n";
//
//        // Respond to input
//        if (playerInput == "1") {
//            int damageDealt = player.attackOpponent(enemy);
//            std::cout << "You dealt " << damageDealt << " damage";
//        }
//        else if (playerInput == "2") {
//            int healAmount = player.heal();
//
//            std::cout << "You healed for " << healAmount;
//        }
//        else if (playerInput == "3") {
//            std::cout << "You chose to do nothing...";
//        }
//        else {
//            std::cout << "Input not valid";
//        }
//
//        std::cout << "\n";
//    } while (playerInput != "1" && playerInput != "2" && playerInput != "3");
//}
//
//void handleEnemyAction(Character& player, Character& enemy) {
//    int enemyChoice = rand() % 3;
//    
//    if (enemyChoice == 0) {
//        int damageDealt = enemy.attackOpponent(player);
//        std::cout << "Enemy dealt " << damageDealt << " damage to you";
//    }
//    else if (enemyChoice == 1) {
//        int healAmount = enemy.heal();
//
//        std::cout << "Enemy healed for " << healAmount;
//    }
//    else if (enemyChoice == 2) {
//        std::cout << "Enemy chose to do nothing...";
//    }
//
//    std::cout << "\n";
//}
//
//void dropItem(Character& player, Character& enemy) {
//    std::string enemyItem = enemy.getItem(0);
//
//    if (enemyItem != "") {
//        player.addItem(enemyItem);
//        std::cout << "Enemy dropped \"" << enemyItem << "\"!!!           \n";
//    }
//}
//
//void handleEnemyDeath(Character& player, Character& enemy, int& currentEnemyIndex, int& enemyCount) {
//    std::cout << "Enemy died!\n";
//    if (currentEnemyIndex < enemyCount) {
//        currentEnemyIndex++;
//    }
//
//    int dropChance = rand() % 10 + 1;
//    if (dropChance <= 3) {
//        dropItem(player, enemy);
//    }
//}
//
//void displayControls() {
//    std::cout << "| Press 1 to attack          |\n";
//    std::cout << "| Press 2 to heal            |\n";
//    std::cout << "| Press 3 to do nothing      |\n";
//}
//
//void win() {
//    std::cout << "You won!\n";
//}
//
//void lose() {
//    std::cout << "You lost...\n";
//}
//
//int main()
//{
//    srand(time(NULL));
//
//    Character player(20, 10, 3, 5, 10);
//
//    int enemyCount = 5;
//    Character* enemies = new Character[enemyCount];
//
//    //Difficulty multiplier for enemies
//    const float difficultyMult = 0.5f;
//
//    // Randomize enemy stats
//    for (unsigned int i = 0; i < enemyCount; i++) {
//        float mult = 1 + i * difficultyMult;
//        float totalStats = 4.0f * mult + i + 4;
//
//        int randHealth = rand() % (int)(totalStats - 3) + 1;
//        totalStats -= randHealth;
//
//        int randAttack = rand() % (int)(totalStats - 2) + 1;
//        totalStats -= randAttack;
//
//        int randDefense = rand() % (int)(totalStats - 1) + 1;
//        totalStats -= randDefense;
//
//        int randAgility = (int)totalStats;
//        
//        enemies[i].setStats(randHealth, randAttack, randDefense, randAgility);
//
//        enemies[i].addItem("itemDrop");
//    }
//
//    int turnCount = 0;
//    int currentEnemyIndex = 0;
//
//    while (player.getHealth() > 0 && currentEnemyIndex < enemyCount) {
//        // Update the current turn
//        turnCount++;
//
//        Character& curEnemy = enemies[currentEnemyIndex];
//
//        std::cout << "------------------------------\n";
//        std::cout << "| Turn: " << turnCount << "  |   Your stats:   |\n";
//        std::cout << "|----------------------------|\n";
//        std::cout << "  HP: " << player.getHealth() << " | ATK: " << player.getAttack() << " | DEF: " << player.getDefense() << "  \n";
//        std::cout << "|----------------------------|\n";
//        std::cout << "| Enemy " << currentEnemyIndex + 1 << "/" << enemyCount << " |  Enemy stats  | \n";
//        std::cout << "|----------------------------|\n";
//        std::cout << "  HP: " << curEnemy.getHealth() << " | ATK: " << curEnemy.getAttack() << " | DEF: " << curEnemy.getDefense() << "  \n";
//        std::cout << "|----------------------------|\n";
//
//        displayControls();
//
//        if (player.getAgility() >= curEnemy.getAgility()) {
//            handlePlayerAction(player, curEnemy);
//            if (curEnemy.isDead()) {
//                handleEnemyDeath(player, curEnemy, currentEnemyIndex, enemyCount);
//            }
//            else {
//                handleEnemyAction(player, curEnemy);
//            }
//        }
//        else {
//            handleEnemyAction(player, curEnemy);
//            handlePlayerAction(player, curEnemy);
//            if (curEnemy.isDead()) {
//                handleEnemyDeath(player, curEnemy, currentEnemyIndex, enemyCount);
//            }
//        }
//        
//        std::cout << "\n";
//    }
//
//    if (player.getHealth() > 0) {
//        win();
//    }
//    else {
//        lose();
//    }
//
//    std::cout << "You defeated " << currentEnemyIndex << " out of " << enemyCount << " monsters\n";
//    
//    // Restart program
//    RestartProgram::Restart(&main);
//    return 0;
//}

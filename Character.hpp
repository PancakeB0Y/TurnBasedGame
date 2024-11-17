#pragma once

#include <iostream>

class Character {
    private:
        std::string name;
        std::string spriteFile;
        int health;
        int attack;
        int defense;
        int agility;

        int inventorySize;
        std::string* inventory;

    public:
        Character(std::string name, std::string spriteFile, int health = 1, int attack = 1, int defense = 0, int agility = 0, int inventorySize = 3);

        ~Character();

        void setStats(int health, int attack, int defense, int agility);

        // Stat getter and setters
        int getHealth() const;
        int getAttack() const;
        int getDefense() const;
        int getAgility() const;
        std::string getName() const;
        std::string getSpriteFile() const;

        void setHealth(const int newHealth);
        void setAttack(const int newAttack);
        void setDefense(const int newDefense);
        void setAgility(const int newAgility);

        void addItem(std::string item);

        //Returns the item at the specified index
        std::string getItem(int index = 0);

        //Remove item from inventory
        void removeItem(int index);

        void printInvetory();

        bool isDead();

        int attackOpponent(Character& opponent);

        int heal();

        void printStats();
};
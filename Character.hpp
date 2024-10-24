#pragma once

#include <iostream>

class Character {
    private:
        int health;
        int attack;
        int defense;
        int agility;

        int inventorySize;
        std::string* inventory;

    public:
        Character(int health = 1, int attack = 1, int defense = 0, int agility = 0, int inventorySize = 3);

        ~Character();

        void setStats(int health, int attack, int defense, int agility);

        // Health getter
        int getHealth() const;

        // Stat getter and setters
        // Health setter
        void setHealth(const int newHealth);

        // Attack getter
        int getAttack() const;

        // Attack setter
        void setAttack(const int newAttack);

        // Defense getter
        int getDefense() const;

        // Defense setter
        void setDefense(const int newDefense);

        // Agility getter
        int getAgility() const;

        // Agility setter
        void setAgility(const int newAgility);

        //Add item to inventory
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
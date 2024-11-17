#include "Character.hpp"

Character::Character(std::string name, std::string spriteFile, int health, int attack, int defense, int agility, int inventorySize)
    : name(name), spriteFile(spriteFile), health(health), attack(attack), defense(defense), agility(agility), inventorySize(inventorySize) {

    inventory = new std::string[inventorySize];
}

Character::~Character() {
    delete[] inventory;
}

void Character::setStats(int health, int attack, int defense, int agility) {
    this->health = health;
    this->attack = attack;
    this->defense = defense;
    this->agility = agility;
}

// Stat getter and setters
int Character::getHealth() const { return this->health; }
int Character::getAttack() const { return this->attack; }
int Character::getDefense() const { return this->defense; }
int Character::getAgility() const { return this->agility; }
std::string Character::getName() const { return this->name; }
std::string Character::getSpriteFile() const { return this->spriteFile; }

void Character::setHealth(const int newHealth) { this->health = newHealth; }
void Character::setAttack(const int newAttack) { this->attack = newAttack; }
void Character::setDefense(const int newDefense) { this->defense = newDefense; }
void Character::setAgility(const int newAgility) { this->agility = newAgility; }

//Add item to inventory
void Character::addItem(std::string item) {
    bool itemAdded = false;

    for (int i = 0; i < inventorySize; i++) {
        if (inventory[i] == "") {
            inventory[i] = item;
            itemAdded = true;
            break;
        }
    }

    if (!itemAdded) {
        std::cout << "Inventory is full";
    }
}

//Returns the item at the specified index
std::string Character::getItem(int index)
{
    return inventory[index];
}

//Remove item from inventory
void Character::removeItem(int index) {
    for (unsigned int i = index + 1; i < inventorySize; i++)
    {
        if (i > 0) {
            inventory[i - 1] = inventory[i];
        }
    }

    inventory[inventorySize - 1] = "";
}

void Character::printInvetory() {
    for (int i = 0; i < inventorySize; i++) {
        if (inventory[i] != "") {
            std::cout << "[" << inventory[i] << "] ";
        }
        else {
            std::cout << "[]" << " ";
        }
    }

    std::cout << "\n";
}

bool Character::isDead() {
    return this->health <= 0;
}

int Character::attackOpponent(Character& opponent) {
    if (isDead()) {
        return 0;
    }

    int opponentHealth = opponent.getHealth();

    // Calculate attack damage
    int damageValue = this->attack - opponent.getDefense();
    if (damageValue < 0) {
        damageValue = 0;
    }

    opponent.setHealth(opponent.getHealth() - damageValue);

    return damageValue;
}

int Character::heal() {
    int healAmount = rand() % (defense + 1);
    this->health += healAmount;

    return healAmount;
}

void Character::printStats() {
    std::cout << this->health << " " << this->attack << " " << this->defense << " " << this->agility << "\n";
    //std::cout << "total stats " << health + attack + defense + agility << "\n";
}





#include "GameObject.hpp"
#include "Scene.hpp";

GameObject::GameObject(Scene& parentScene, std::string identifier, sf::Vector2f position, GameObject* parent) : parentScene(parentScene), window(parentScene.getRenderWindow()), identifier(identifier), position(position), parent(parent) {
	parentScene.addGameObject(this);
}

GameObject::~GameObject(){ }

std::string GameObject::getIdentifier() const { return std::string(); }

sf::Vector2f GameObject::getPosition() const { return position; }

void GameObject::setPosition(sf::Vector2f position)
{
	this->position = position;
}

GameObject* GameObject::getParent() const { return parent; }

void GameObject::setParent(GameObject* parent)
{
	this->parent = parent;
}

void GameObject::removeParent()
{
	this->parent = NULL;
}

void GameObject::addChild(GameObject* gameObject)
{
	this->listOfChildren.push_back(gameObject);
	gameObject->setParent(this);

	//Check if it already has parent
	//If it has remove it as a child from that parent
}

void GameObject::removeChild(int index)
{
	listOfChildren.at(index)->setParent(NULL);
	listOfChildren.erase(listOfChildren.begin() + index);
}

void GameObject::removeChild(GameObject* gameObject)
{
	for (unsigned int i = 0; i < listOfChildren.size(); i++)
	{
		if (listOfChildren[i]->getIdentifier() == gameObject->getIdentifier()) {
			gameObject->setParent(NULL);
			listOfChildren.erase(listOfChildren.begin() + i);
			break;
		}
	}
}

void GameObject::removeChild(std::string identifier)
{
	for (unsigned int i = 0; i < listOfChildren.size(); i++)
	{
		if (listOfChildren[i]->getIdentifier() == identifier) {
			listOfChildren[i]->setParent(NULL);
			listOfChildren.erase(listOfChildren.begin() + i);
			break;
		}
	}
}

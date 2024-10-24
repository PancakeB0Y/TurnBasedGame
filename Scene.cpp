#include "Scene.hpp"

Scene::Scene(std::string identifier, sf::RenderWindow& window) : identifier(identifier), window(window) { }

Scene::~Scene(){}

void Scene::update()
{
	for (unsigned int i = 0; i < this->listOfGameObjects.size(); i++)
	{
		listOfGameObjects[i]->update();
	}
}

void Scene::render()
{
	for (unsigned int i = 0; i < this->listOfGameObjects.size(); i++)
	{
		listOfGameObjects[i]->render();
	}
}

std::string Scene::getIdentifier() const { return std::string(); }

sf::RenderWindow& Scene::getRenderWindow() const { return window; }

void Scene::addGameObject(GameObject* gameObject)
{
	this->listOfGameObjects.push_back(gameObject);
}

void Scene::removeGameObject(int index)
{
	listOfGameObjects.erase(listOfGameObjects.begin() + index);
}

void Scene::removeGameObject(GameObject* gameObject)
{
	for (unsigned int i = 0; i < listOfGameObjects.size(); i++)
	{
		if (listOfGameObjects[i]->getIdentifier() == gameObject->getIdentifier()) {
			listOfGameObjects.erase(listOfGameObjects.begin() + i);
			break;
		}
	}
}

void Scene::removeGameObject(std::string identifier)
{
	for (unsigned int i = 0; i < listOfGameObjects.size(); i++)
	{
		if (listOfGameObjects[i]->getIdentifier() == identifier) {
			listOfGameObjects[i]->setParent(NULL);
			listOfGameObjects.erase(listOfGameObjects.begin() + i);
			break;
		}
	}
}

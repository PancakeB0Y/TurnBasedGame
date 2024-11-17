#pragma once

#include <string>
#include <SFML/Graphics/RenderWindow.hpp>

#include "GameObject.hpp"

class Scene
{
	private:
		const std::string identifier;
		std::string spriteFile;
		std::vector<GameObject*> listOfGameObjects;
		sf::RenderWindow& window;

	public:
		Scene(std::string identifier, sf::RenderWindow& window);
		virtual ~Scene();

		void handleEvent(const sf::Event& event);
		void update();
		void render();
		std::string getIdentifier() const;

		
		sf::RenderWindow& getRenderWindow() const;
		void addGameObject(GameObject* gameObject);
		void removeGameObject(int index);
		void removeGameObject(GameObject* gameObject);
		void removeGameObject(std::string identifier);
};


#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

class Scene;

class GameObject
{
	protected:
		const std::string identifier;
		sf::Vector2f position;
		GameObject* parent;
		Scene& parentScene;
		sf::RenderWindow& window;

		std::vector<GameObject*> listOfChildren;
		
	public:
		GameObject(Scene& parentScene, std::string identifier, sf::Vector2f position = sf::Vector2f(0, 0), GameObject* parent = NULL);
		virtual ~GameObject();

		virtual void update() = 0;
		virtual void render() = 0;

		std::string getIdentifier() const;
		sf::Vector2f getPosition() const;
		virtual void setPosition(const sf::Vector2f position);

		GameObject* getParent() const;
		void setParent(GameObject* parent);
		void removeParent();

		void addChild(GameObject* gameObject);
		void removeChild(int index);
		void removeChild(GameObject* gameObject);
		void removeChild(std::string identifier);
};


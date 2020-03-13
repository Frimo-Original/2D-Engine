#pragma once

#include <SFML/Graphics.hpp>

#include <string>

#include "GameScene.h"
#include "Textures.h"
#include "GameTexture.h"
#include "Vector2f.h"

namespace Engine
{
	class GameScene;

	class GameObject
	{
	private:
		GameScene* scene;
		Textures* textures;
		sf::Texture* texture;

		std::string id;

		Vector2f speed = { 0, 0 };
		Vector2i position;
		Vector2i size;

	public:
		GameObject(GameScene* scene, std::string id, Textures* textures, Vector2i size);
		~GameObject();

		std::string getId();

		void setTextures(Textures* textures);
		void setTexture(int number);

		void setSize(Vector2i size);
		Vector2i getSize();

		void setPosition(Vector2i position);
		Vector2i getPosition();

		void setSpeed(Vector2f speed);
		Vector2f getSpeed();

		GameScene* getScene();

		virtual void run(int time) = 0;

		void draw(sf::RenderWindow* window);
	};
}
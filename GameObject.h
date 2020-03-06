#pragma once

#include <SFML/Graphics.hpp>

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

		Vector2f speed = { 0, 0 };
		Vector2i position = {0, 0};
		Vector2i size;

	public:
		GameObject(GameScene* scene, Textures* textures, Vector2i size);
		~GameObject();

		void setTextures(Textures* textures);
		void setTexture(int number);

		void setSize(Vector2i size);
		Vector2i getSize();

		void setPosition(Vector2i position);
		Vector2i getPosition();

		void setSpeed(Vector2f speed);
		Vector2f getSpeed();

		virtual void run() = 0;

		void draw(sf::RenderWindow* window);

	};
}
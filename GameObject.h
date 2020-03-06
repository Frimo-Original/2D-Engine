#pragma once

#include <SFML/Graphics.hpp>

#include "GameScene.h"
#include "Textures.h"
#include "GameTexture.h"

namespace Engine
{
	class GameScene;

	class GameObject
	{
	private:
		GameScene* scene;
		Textures* textures;
		sf::Texture* texture;

	public:
		GameObject(GameScene* scene, Textures* textures);
		~GameObject();

		void setTextures(Textures* textures);

		void setTexture(int number);

		virtual void run() = 0;

		void draw(sf::RenderWindow* window);
	};
}
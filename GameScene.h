#pragma once

#include <SFML/Graphics.hpp>

#include <vector>
#include <string>

#include <iostream>

#include "Textures.h"
#include "Floor.h"
#include "GameObject.h"
#include "Vector2i.h"

namespace Engine
{
	class GameObject;

	class GameScene
	{
	private:
		int** scene;

		Vector2i count;
		Vector2i size;

		Textures* textures;
		Floor* floor = NULL;
		std::vector<GameObject*> gameObjects;

	public:
		GameScene(Vector2i count, Vector2i size, Textures* textures);
		~GameScene();

		void setFloor(Floor* floor);
		void setTextures(Textures* textures);
		void draw(sf::RenderWindow* window);

		Vector2i getCount();

		void addObject(GameObject* object);
		void deleteObject(GameObject* object);

		void fillScene(int value);
		void setWalls(int numberRow, std::string row);
	};
}
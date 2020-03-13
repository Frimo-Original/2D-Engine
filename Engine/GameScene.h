#pragma once

#include <SFML/Graphics.hpp>

#include <vector>
#include <string>

#include <iostream>

#include "Textures.h"
#include "Floor.h"
#include "GameObject.h"
#include "Vector2i.h"
#include "Window.h"

namespace Engine
{
	class GameObject;
	class Window;

	class GameScene
	{
	protected:
		int** scene;

		Window* window;

		Vector2i count;
		Vector2i size;

		Textures* textures;
		Floor* floor = NULL;
		std::vector<GameObject*> gameObjects;

	public:
		GameScene(Vector2i count, Vector2i size, Textures* textures, Window* window);
		~GameScene();

		void setFloor(Floor* floor);
		void setTextures(Textures* textures);

		void draw(sf::RenderWindow* window);
		//void run(int time);
		virtual void run(int time) = 0;

		void setView(sf::View view);

		Vector2i getCount();
		Vector2i getSize();

		void addObject(GameObject* object);
		void deleteObject(GameObject* object);

		void fillScene(int value);
		void setWalls(int numberRow, std::string row);

		Vector2i getCellPosition(Vector2i coordinats);
		bool isWall(Vector2i positions, Vector2i size);
	};
}
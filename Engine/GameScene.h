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
		void run(int time);

		Vector2i getCount();
		Vector2i getSize();

		void addObject(GameObject* object);
		void deleteObject(GameObject* object);

		void fillScene(int value);
		void setWalls(int numberRow, std::string row);

		Vector2i getCellPosition(Vector2i coordinats);
		//bool isWall(Vector2i cellPosition);
		bool isWall(Vector2i positions, Vector2i size);
		/*bool checkWall(Vector2i positions, Vector2i size)
		{
			int countPointsX = getSize().getX() / size.getX() + 1;
			int countPointsY = getSize().getY() / size.getY() + 1;

			for (int i = 0; i < countPointsY; i++)
				for (int j = 0; j < countPointsX; j++)
				{
					std::cout << size.getY() / countPointsY - 1 << std::endl;

					Vector2i cellPosition = getCellPosition({ positions.getX() + (size.getX() / (countPointsX - 1)) * j,
						positions.getY() + (size.getY() / (countPointsY - 1)) * i });

					if (cellPosition.getX() < 0 || cellPosition.getY() < 0 || scene[cellPosition.getY()][cellPosition.getX()] >= 1 ||
						cellPosition.getX() > count.getX() || cellPosition.getY() > count.getY())
						return true;
				}
			return false;
		}*/
	};
}
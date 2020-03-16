#include "OneScene.h"
#include "Player.h"
#include "Bullet.h"

#include <math.h>

#include <iostream>

OneScene::OneScene(Window* window) : GameScene({ 44, 28 }, { 40, 40 }, NULL, window) {
	Textures* texturesLevels = new Textures();
	texturesLevels->addTexture(1, "Textures/Levels/One/Walls/Wall_1.png");
	setTextures(texturesLevels);
	setFloor(new Floor({ 22, 14 }, { 128, 128 }, new GameTexture("Textures/Levels/One/Floors/Floor.png")));
	setWalls(0, "0000100000");
	setWalls(1, "0000100000");
	setWalls(2, "0000100000");
	setWalls(5, "1111100000");

	addObject(new Player(this, { 25, 32 }));
}

void OneScene::run(int time)
{
	GameScene::run(time);

	Vector2i centerPlayer;
	Vector2i sizeScene = { count.getX() * size.getX(), count.getY() * size.getY() };
	sf::View view = window->getView();

	for (GameObject* obj : gameObjects) {
		if (obj->getId() == "Player")
		{
			Vector2i positionsPlayer = obj->getPosition();
			Vector2i sizePlayer = obj->getSize();
			Vector2i sizeWindow = window->getSize();
			centerPlayer = { positionsPlayer.getX() + sizePlayer.getX() / 2, positionsPlayer.getY() + sizePlayer.getY() / 2 };
			Vector2i centerWindow = { sizeWindow.getX() / 2, sizeWindow.getY() / 2 };

			if (centerPlayer.getX() > centerWindow.getX() && centerPlayer.getX() < sizeScene.getX() - centerWindow.getX())
				view.setCenter({ (float)(centerPlayer.getX()), view.getCenter().y });
			
			if (centerPlayer.getY() > centerWindow.getY() && centerPlayer.getY() < sizeScene.getY() - centerWindow.getY())
				view.setCenter({ view.getCenter().x, (float)(centerPlayer.getY()) });

			window->setView(view);
		}
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		Vector2i mouseClick = window->getMousePosition();
		Vector2i mousePosition = { (int)(view.getCenter().x - view.getSize().x / 2 + mouseClick.getX()),
		(int)(view.getCenter().y - view.getSize().y / 2 + mouseClick.getY()) };

		float x = centerPlayer.getX() - mousePosition.getX(), y = centerPlayer.getY() - mousePosition.getY();
		float difference = sqrt(x * x + y * y) / 0.6;  //0.6 - module speed bullet
		//std::cout << x / difference << " " << y / difference << " " << difference << std::endl;
	
		addObject(new Bullet(this, centerPlayer, { x / difference, y / difference }));
	}
}
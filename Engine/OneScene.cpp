#include "OneScene.h"
#include "Player.h"

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
	for (GameObject* obj : gameObjects) {
		obj->run(time);

		if (obj->getId() == "Player") {
			Vector2i positionsPlayer = obj->getPosition();
			Vector2i sizePlayer = obj->getSize();
			Vector2i sizeWindow = window->getSize();
			Vector2i sizeScene = { count.getX() * size.getX(), count.getY() * size.getY() };

			sf::View view;
			view.setSize(sizeWindow.getX(), sizeWindow.getY());

			if (positionsPlayer.getX() <= sizeWindow.getX() / 2 - sizePlayer.getX() / 2)
				view.setCenter(sf::Vector2f(sizeWindow.getX() / 2, view.getCenter().y));
			else if (positionsPlayer.getX() >= sizeScene.getX() - sizeWindow.getX() / 2 - sizePlayer.getX() / 2)
				view.setCenter(sf::Vector2f(sizeScene.getX() - sizeWindow.getX() / 2, view.getCenter().y));
			else
				view.setCenter(sf::Vector2f(positionsPlayer.getX() + sizePlayer.getX() / 2, view.getCenter().y));

			if (positionsPlayer.getY() <= sizeWindow.getY() / 2 - sizePlayer.getY() / 2)
				view.setCenter(sf::Vector2f(view.getCenter().x, sizeWindow.getY() / 2));
			else if (positionsPlayer.getY() >= sizeScene.getY() - sizeWindow.getY() / 2 - sizePlayer.getY() / 2)
				view.setCenter(sf::Vector2f(view.getCenter().x, sizeScene.getY() - sizeWindow.getY() / 2));
			else
				view.setCenter(sf::Vector2f(view.getCenter().x, positionsPlayer.getY() + sizePlayer.getY() / 2));

			window->setView(view);
		}
	}
}
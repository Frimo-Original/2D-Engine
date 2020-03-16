#include "OneScene.h"
#include "Player.h"
#include "Bullet.h"

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
	Vector2i positionsPlayer;
	Vector2i sizePlayer;
	Vector2i sizeWindow = window->getSize();

	Vector2i sizeScene = { count.getX() * size.getX(), count.getY() * size.getY() };

	sf::View view = window->getView();
	GameScene::run(time);

	for (GameObject* obj : gameObjects) {
		if (obj->getId() == "Player")
		{
			Vector2i positionsPlayer = obj->getPosition();
			Vector2i sizePlayer = obj->getSize();
			Vector2i centerPlayer = { positionsPlayer.getX() + sizePlayer.getX() / 2, positionsPlayer.getY() + sizePlayer.getY() / 2 };
			Vector2i centerWindow = { sizeWindow.getX() / 2, sizeWindow.getY() / 2 };

			if (centerPlayer.getX() > centerWindow.getX() && centerPlayer.getX() < sizeScene.getX() - centerWindow.getX())
				view.setCenter({ (float)(centerPlayer.getX()), view.getCenter().y });
			
			if (centerPlayer.getY() > centerWindow.getY() && centerPlayer.getY() < sizeScene.getY() - centerWindow.getY())
				view.setCenter({ view.getCenter().x, (float)(centerPlayer.getY()) });

			window->setView(view);
		}
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		/*if (positionsPlayer.getX() > sizeWindow.getX() / 2 &&
			positionsPlayer.getX() < sizeScene.getX() - sizeWindow.getX() / 2)
		{
			Vector2i positionsBullet = { positionsPlayer.getX() - ((int)view.getSize().x / 2 - window->getMousePosition().getX()),
			positionsPlayer.getY() - ((int)view.getSize().y / 2 - window->getMousePosition().getY()) };
			addObject(new Bullet(this, positionsBullet, { 0, 0 }));
		}
		else {*/
			addObject(new Bullet(this, window->getMousePosition(), { 0, 0 }));
		//}
	}
}
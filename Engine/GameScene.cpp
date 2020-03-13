
#include "GameScene.h"

Engine::GameScene::GameScene(Vector2i count, Vector2i size, Textures* textures, Window* window) : count(count),
size(size), textures(textures), window(window)
{
	scene = new int* [count.getY()];

	for (int i = 0; i < count.getY(); i++)
		scene[i] = new int[count.getX()];

	fillScene(0);
}

Engine::GameScene::~GameScene()
{
	for (int i = 0; i < count.getY(); i++)
		delete[] scene[i];

	delete[] scene;

	delete textures;
	delete floor;
}

void Engine::GameScene::setView(sf::View view) {
	window->setView(view);
}

Engine::Vector2i Engine::GameScene::getCount() {
	return count;
}

Engine::Vector2i Engine::GameScene::getSize() {
	return size;
}

void Engine::GameScene::addObject(GameObject* object) {
	gameObjects.push_back(object);
}

void Engine::GameScene::deleteObject(GameObject* object) {
	for (int i = 0; i < gameObjects.size(); i++)
		if (gameObjects[i] == object) {
			delete gameObjects[i];
			gameObjects.erase(gameObjects.begin() + i);
		}
}

void Engine::GameScene::setFloor(Floor* floor) {
	delete this->floor;
	this->floor = floor;
}

void Engine::GameScene::fillScene(int value) {
	for (int i = 0; i < count.getY(); i++)
		for (int j = 0; j < count.getX(); j++)
			scene[i][j] = value;
}

void Engine::GameScene::setTextures(Textures* textures) {
	delete this->textures;
	this->textures = textures;
}

void Engine::GameScene::run(int time)
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

void Engine::GameScene::draw(sf::RenderWindow* window)
{
	if (floor != NULL)
		floor->draw(window);

	for (int i = 0; i < count.getY(); i++)
		for (int j = 0; j < count.getX(); j++)
			if (scene[i][j] != 0) {
				sf::Sprite sprite(*textures->getTexture(scene[i][j]));
				sprite.setPosition(j * size.getX(), i * size.getY());
				window->draw(sprite);
			}

	for (GameObject* obj : gameObjects)
		obj->draw(window);
}

void Engine::GameScene::setWalls(int numberRow, std::string row)
{
	if (numberRow >= 0 && numberRow <= count.getY())
		for (int i = 0; i < row.length(); i++) {
			if (row[i] >= '0' && row[i] <= '9') {
				char c = row[i];
				scene[numberRow][i] = atoi(&c);
			}
		}
}

Engine::Vector2i Engine::GameScene::getCellPosition(Engine::Vector2i coordinats) {
	Vector2i cellPosition = { 0, 0 };
	
	if (coordinats.getX() < 0)
		cellPosition.setX(-1);
	else
		cellPosition.setX((int)(coordinats.getX() / size.getX()));
	if (coordinats.getY() < 0)
		cellPosition.setY(-1);
	else
		cellPosition.setY((int)(coordinats.getY() / size.getY()));

	return cellPosition;
}

bool Engine::GameScene::isWall(Vector2i positions, Vector2i size)
{
	int countPointsX = getSize().getX() / size.getX() + 1;
	int countPointsY = getSize().getY() / size.getY() + 1;

	for (int i = 0; i < countPointsY; i++)
		for (int j = 0; j < countPointsX; j++)
		{
			Vector2i cellPosition = getCellPosition({ positions.getX() + (size.getX() / (countPointsX - 1)) * j,
				positions.getY() + (size.getY() / (countPointsY - 1)) * i });

			if (cellPosition.getX() < 0 || cellPosition.getY() < 0 || cellPosition.getX() >= count.getX() ||
				cellPosition.getY() >= count.getY()
				|| scene[cellPosition.getY()][cellPosition.getX()] >= 1)
				return true;
		}

	return false;
}
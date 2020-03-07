
#include "GameScene.h"

Engine::GameScene::GameScene(Vector2i count, Vector2i size, Textures* textures) : count(count),
size(size), textures(textures)
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

Engine::Vector2i Engine::GameScene::getCount() {
	return count;
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

void Engine::GameScene::run(int time) {
	for (GameObject* obj : gameObjects)
		obj->run(time);
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
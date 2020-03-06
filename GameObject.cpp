#include "GameObject.h"

Engine::GameObject::GameObject(GameScene* scene, Textures* textures, Vector2i size) :
	scene(scene), textures(textures), size(size) { }

Engine::GameObject::~GameObject() {
	delete textures;
}

void Engine::GameObject::setTextures(Textures* textures) {
	delete this->textures;
	this->textures = textures;
}

void Engine::GameObject::setTexture(int number) {
	this->texture = textures->getTexture(number);
}

void Engine::GameObject::draw(sf::RenderWindow* window) {
	window->draw(sf::Sprite(*texture));
}

void Engine::GameObject::setSize(Vector2i size) {
	this->size = size;
}

Engine::Vector2i Engine::GameObject::getSize() {
	return size;
}

void Engine::GameObject::setPosition(Engine::Vector2i position) {
	this->position = position;
}

Engine::Vector2i Engine::GameObject::getPosition() {
	return position;
}

void Engine::GameObject::setSpeed(Engine::Vector2f speed) {
	this->speed = speed;
}

Engine::Vector2f Engine::GameObject::getSpeed() {
	return speed;
}
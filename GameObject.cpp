#include "GameObject.h"

Engine::GameObject::GameObject(GameScene* scene, Textures* textures) : scene(scene), textures(textures) { }

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
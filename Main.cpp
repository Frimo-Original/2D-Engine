#pragma once

#include "GameScene.h"
#include "Window.h"
#include "FirstLevel.h"

#include <iostream>

using namespace Engine;

int main()
{
    Window* window = new Window(1100, 700, "Game", false);

    window->setGameScene(FirstLevel().getGameScene());

    window->launch();
    window->close();

	return 0;
}

class Player : public GameObject
{
public:
    Player(GameScene* scene, Textures* textures, Vector2i size) : GameObject(scene, textures, size) { }

    void run() override {

    }
};
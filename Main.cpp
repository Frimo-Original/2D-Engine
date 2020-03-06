#pragma once

#include "GameScene.h"
#include "Window.h"
#include <iostream>

using namespace Engine;

int main()
{
    Window* window = new Window(1100, 700, "Game", false);

    Textures* texturesLevels = new Textures();
    texturesLevels->addTexture(1, "wall.png");

    GameScene* oneLevel = new GameScene({ 44, 28 }, { 50, 50 }, texturesLevels);
    oneLevel->setFloor(new Floor({ 22, 14 }, { 201, 199 }, new GameTexture("floor_test.png")));
    oneLevel->setWalls(0, "0001000001");
    oneLevel->setWalls(1, "0001000001");
    oneLevel->setWalls(2, "0001000001");
    window->setGameScene(oneLevel);

    //GameObject* player = new GameObject(oneLevel);

    window->launch();
    window->close();

	return 0;
}

class Player : public GameObject
{
public:
    void run() override {

    }
};
#pragma once

#include "GameScene.h"
#include "Player.h"
#include "Vector2i.h"

using namespace Engine;

class FirstLevel
{
public:
	GameScene* scene;

	FirstLevel();

	GameScene* getGameScene();
};
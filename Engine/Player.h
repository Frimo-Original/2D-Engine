#pragma once

#include "GameObject.h"
#include "PhysicalFunction.h"

#include <math.h>

#include <SFML/Graphics.hpp>

using namespace Engine;

class Player : public GameObject
{
	//Player(GameScene* scene, Textures* textures, Vector2i size);
public:
	Player(GameScene* scene, Vector2i size);

	void run(int time) override;
};
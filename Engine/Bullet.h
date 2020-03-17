#pragma once

#include "GameObject.h"

using namespace Engine;

class Bullet : public GameObject
{
public:
	Bullet(GameScene* scene, Vector2f positions, Vector2f speed);
	void run(int time) override;
};
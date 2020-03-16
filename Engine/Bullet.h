#pragma once

#include "GameObject.h"

using namespace Engine;

class Bullet : public GameObject
{
private:
	

public:
	Bullet(GameScene* scene, Vector2i positions, Vector2f speed);
	void run(int time) override;
};
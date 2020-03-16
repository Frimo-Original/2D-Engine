#include "Bullet.h"

Bullet::Bullet(GameScene* scene, Vector2i positions, Vector2f speed) :
	GameObject(scene, "Bullet", NULL, {7, 7})
{
    Textures* textures = new Textures();
    textures->addTexture(0, "Textures/Bullets/Bullet.png");

    setTextures(textures);
    setTexture(0);
    setPosition(positions);
    setSpeed(speed);
}

void Bullet::run(int time) {
    Vector2i newPositions = { getPosition().getX() + (int)(speed.getX() * time), getPosition().getY() + (int)(speed.getY() * time)};  //TODO: in static functions to Functions class

    if (!scene->isWall(newPositions, size)) {
        setPosition(newPositions);
    }
    else
        setStatusDelete(true);
}
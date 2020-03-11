#include "Player.h"

#include <iostream>

Player::Player(GameScene* scene, Vector2i size) : GameObject(scene, NULL, size) {
    Textures* textures = new Textures();
    textures->addTexture(0, "Textures/Humans/Human.png");
    textures->addTexture(1, "Textures/Humans/Human_bottom.png");
    textures->addTexture(2, "Textures/Humans/Human_left.png");
    textures->addTexture(3, "Textures/Humans/Human_right.png");
    setTextures(textures);
    setTexture(0);
}

void Player::run(int time)
{
    float accelerationRun = 0.01;
    float accelerationStop = 0.003;
    float maxSpeed = 0.3;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        if (getSpeed().getX() >= 0) {
            float speed = PhysicalFunction::getSpeed(getSpeed().getX(), accelerationRun, time);

            if (speed < maxSpeed)
                setSpeed({ speed, getSpeed().getY() });
            else
                setSpeed({ maxSpeed, getSpeed().getY() });
        }

        else if (getSpeed().getX() < 0) {
            float speed = PhysicalFunction::getSpeed(getSpeed().getX(), (accelerationRun + accelerationStop), time);

            if (speed > 0)
                setSpeed({ 0, getSpeed().getY() });
            else
                setSpeed({ speed, getSpeed().getY() });
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        if (getSpeed().getX() <= 0) {
            float speed = PhysicalFunction::getSpeed(getSpeed().getX(), -accelerationRun, time);

            if (speed > -maxSpeed)
                setSpeed({ speed, getSpeed().getY() });
            else
                setSpeed({ -maxSpeed, getSpeed().getY() });
        }
        else if (getSpeed().getX() > 0) {
            float speed = PhysicalFunction::getSpeed(getSpeed().getX(), -(accelerationRun + accelerationStop), time);

            if (speed <= 0)
                setSpeed({ 0, getSpeed().getY() });
            else
                setSpeed({ speed, getSpeed().getY() });
        }
    }
    else
    {
        if (getSpeed().getX() > 0) {
            float speed = PhysicalFunction::getSpeed(getSpeed().getX(), -accelerationStop, time);

            if (speed <= 0)
                setSpeed({ 0, getSpeed().getY() });
            else
                setSpeed({ speed, getSpeed().getY() });
        }
        else if (getSpeed().getX() < 0) {
            float speed = PhysicalFunction::getSpeed(getSpeed().getX(), accelerationStop, time);

            if (speed >= 0)
                setSpeed({ 0, getSpeed().getY() });
            else
                setSpeed({ speed, getSpeed().getY() });
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        if (getSpeed().getY() >= 0) {
            float speed = PhysicalFunction::getSpeed(getSpeed().getY(), accelerationRun, time);

            if (speed < maxSpeed)
                setSpeed({ getSpeed().getX(), speed });
            else
                setSpeed({ getSpeed().getX(), maxSpeed });
        }

        else if (getSpeed().getY() < 0) {
            float speed = PhysicalFunction::getSpeed(getSpeed().getY(), (accelerationRun + accelerationStop), time);

            if (speed > 0)
                setSpeed({ getSpeed().getX(), 0 });
            else
                setSpeed({ getSpeed().getX(), speed });
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        if (getSpeed().getY() <= 0) {
            float speed = PhysicalFunction::getSpeed(getSpeed().getY(), -accelerationRun, time);

            if (speed > -maxSpeed)
                setSpeed({ getSpeed().getX(), speed });
            else
                setSpeed({ getSpeed().getX(), -maxSpeed });
        }
        else if (getSpeed().getY() > 0) {
            float speed = PhysicalFunction::getSpeed(getSpeed().getY(), -(accelerationRun + accelerationStop), time);

            if (speed <= 0)
                setSpeed({ getSpeed().getX(), 0 });
            else
                setSpeed({ getSpeed().getX(), speed });
        }
    }
    else
    {
        if (getSpeed().getY() > 0) {
            float speed = PhysicalFunction::getSpeed(getSpeed().getY(), -accelerationStop, time);

            if (speed <= 0)
                setSpeed({ getSpeed().getX(), 0 });
            else
                setSpeed({ getSpeed().getX(), speed });
        }
        else if (getSpeed().getY() < 0) {
            float speed = PhysicalFunction::getSpeed(getSpeed().getY(), accelerationStop, time);

            if (speed >= 0)
                setSpeed({ getSpeed().getX(), 0 });
            else
                setSpeed({ getSpeed().getX(), speed });
        }
    }

    /*if (getSpeed().getX() != 0) {

        setPosition(getScene()->getMovingX({ (int)(getPosition().getX() + getSpeed().getX() * time), getPosition().getY() }, getSize()));
    }*/

    if (getSpeed().getX() > 0) {
        Vector2i newPosition = { (int)(getPosition().getX() + getSpeed().getX() * time) + getSize().getX(), getPosition().getY() };
        Vector2i newCellPosition = getScene()->getCellPosition(newPosition);

        if (!getScene()->isWall(newCellPosition))
            setPosition({ newPosition.getX() - getSize().getX(), newPosition.getY() });
        else {
            setPosition({ getScene()->getSize().getX() * newCellPosition.getX() - getSize().getX(), newPosition.getY() });
            setSpeed({ 0, getSpeed().getY() });
        }
    }
    else if (getSpeed().getX() < 0) {
        Vector2i newPosition = { (int)(getPosition().getX() + getSpeed().getX() * time), getPosition().getY() };
        Vector2i newCellPosition = getScene()->getCellPosition(newPosition);

        //std::cout << getPosition().getX() << "  " << newCellPosition.getX() << std::endl;

        if (!getScene()->isWall(newCellPosition))
            setPosition({ newPosition.getX(), newPosition.getY() });
        else {
            setPosition({ getScene()->getSize().getX() * (newCellPosition.getX() + 1), newPosition.getY() });
            setSpeed({ 0, getSpeed().getY() });
        }
    }

    if (getSpeed().getY() != 0)
        setPosition({ getPosition().getX(), (int) (getPosition().getY() + getSpeed().getY() * time) });
}
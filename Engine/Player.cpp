#include "Player.h"

#include <iostream>

Player::Player(GameScene* scene, Vector2i size) : GameObject(scene, "Player", NULL, size) {
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
    float accelerationStop = 0.001;  //0.003
    float maxSpeed = 0.3;  //0.3

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

    if (getSpeed().getX() > 0) {
        Vector2i newPosition = { (int)(getPosition().getX() + getSpeed().getX() * time), getPosition().getY() };

        if (!getScene()->isWall(newPosition, getSize()))
            setPosition({ newPosition.getX(), newPosition.getY() });
        else
            setSpeed({ 0, getSpeed().getY() });
    }
    else if (getSpeed().getX() < 0) {
        Vector2i newPosition = { (int)(getPosition().getX() + getSpeed().getX() * time), getPosition().getY() };

        if (!getScene()->isWall(newPosition, getSize()))
            setPosition({ newPosition.getX(), newPosition.getY() });
        else
            setSpeed({ 0, getSpeed().getY() });
    }

    if (getSpeed().getY() > 0) {
        Vector2i newPosition = { getPosition().getX(), (int)(getPosition().getY() + getSpeed().getY() * time) };

        if (!getScene()->isWall(newPosition, getSize()))
            setPosition({ newPosition.getX(), newPosition.getY() });
        else
            setSpeed({ getSpeed().getX(), 0 });
    }
    else if (getSpeed().getY() < 0) {
        Vector2i newPosition = { getPosition().getX(), (int)(getPosition().getY() + getSpeed().getY() * time) };

        if (!getScene()->isWall(newPosition, getSize()))
            setPosition({ newPosition.getX(), newPosition.getY() });
        else
            setSpeed({ getSpeed().getX(), 0 });
    }

    /*sf::View view;
    view.setSize(sf::Vector2f(1100, 750));

    if (getPosition().getX() >= 550)
        view.setCenter(sf::Vector2f(getPosition().getX(), view.getCenter().y));
    else
        view.setCenter(sf::Vector2f(550, view.getCenter().y));

    if (getPosition().getY() >= 375)
        view.setCenter(sf::Vector2f(view.getCenter().x, getPosition().getY()));
    else
        view.setCenter(sf::Vector2f(view.getCenter().x, 375));*/

    
    //view.setCenter(sf::Vector2f(getPosition().getX(), getPosition().getY()));
    //getScene()->setView(view);
}
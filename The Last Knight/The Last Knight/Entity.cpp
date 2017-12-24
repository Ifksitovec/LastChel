#include "Entity.h"
#include <iostream>
#include <cmath>

void Entity::setstay()
{
	state = stay;
}

float Entity::getspeed()
{
	return speed;
}

Gstate Entity::getState()
{
	return state;
}

Sprite Entity::getimage()
{
	return sprite;
}

bool Entity::getLife()
{
	return life;
}

void Entity::setLife(bool l)
{
	life = l;
}

void Entity::setScore(int s)
{
	score += s;
}

int Entity::getScore()
{
	return score;
}

int Entity::getHP()
{
	return hp;
}

//получение позиции по Х персонажа
float Entity::getposX()
{
	return posX;
}

//получение позиции по У персонажа
float Entity::getposY()
{
	return posY;
}

void Entity::changePos(float x, float y)
{
	posX += x;
	posY += y;
}

int Entity::getDamage()
{
	return damage;
}

bool Entity::shoot_delay()
{
	shoot_time = time.getElapsedTime().asMilliseconds();
	if (shoot_time >= delay)
	{
		time.restart();
		return true;
	}
	else
		return false;
}
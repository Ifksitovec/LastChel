#include "Entity.h"
#include <iostream>

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

void Entity::setHP(int h)
{
	hp += h;
}

//��������� ������� �� � ���������
float Entity::getposX()
{
	return posX;
}

//��������� ������� �� � ���������
float Entity::getposY()
{
	return posY;
}


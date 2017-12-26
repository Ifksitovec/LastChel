#include "Entity.h"
#include <iostream>
#include <cmath>

void Entity::SetStay()
{
	state = stay;
}

float Entity::GetSpeed()
{
	return speed;
}

Gstate Entity::GetState()
{
	return state;
}

Sprite Entity::GetImage()
{
	return sprite;
}

bool Entity::GetLife()
{
	return life;
}

void Entity::SetLife(bool l)
{
	life = l;
}

void Entity::SetScore(int s)
{
	score += s;
}

int Entity::GetScore()
{
	return score;
}

int Entity::GetHp()
{
	return hp;
}

//получение позиции по Х персонажа
float Entity::GetPosX()
{
	return PosX;
}

//получение позиции по У персонажа
float Entity::GetPosY()
{
	return PosY;
}

void Entity::ChangePos(float x, float y)
{
	PosX += x;
	PosY += y;
}

int Entity::GetDamage()
{
	return damage;
}

bool Entity::ShootDelay()
{
	ShootTime = time.getElapsedTime().asMilliseconds();
	if (ShootTime >= delay)
	{
		time.restart();
		return true;
	}
	else
		return false;
}

void Entity::SetN(float time)
{
	if (N > 4) N = 0;
	else N += 0.01*time;
}

float Entity::GetN()
{
	return N;
}

FloatRect Entity::GetRect()
{
	if (type == pers) 
	{
		FloatRect FR(PosX, PosY, SizeImg, SizeImg); 
		return FR;
	}
	else
	if (type == arrow)
	{
		FloatRect FR(PosX, PosY, SizeImgArr, SizeImgArr); 
		return FR;
	}
	
}

Gtype Entity::GetType()
{
	return type;
}

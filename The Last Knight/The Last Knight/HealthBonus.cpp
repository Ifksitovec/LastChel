//HealthBonus.cpp
#include "HealthBonus.h"

HealthBonus::HealthBonus(float x, float y)
{
	PrevState = east;//направляющее положение
	state = stay; // начальное положение
	hp = 300;
	PosX = x;
	PosY = y;
	speed = 0;
	type = BonusHp;
	CurrentFrame = 0;
	life = true;
	damage = 200;

	texture.loadFromFile("images/map.png");
	sprite.setTexture(texture);
	sprite.setPosition(PosX, PosY);
	sprite.setTextureRect(IntRect(50, 175, SizeImgMap, SizeImgMap));
}

bool HealthBonus::RadiusDamage(float x,float y)
{
	return true;
}

void HealthBonus::SetHp(int h, Gtype)
{
	hp = hp;
}

void HealthBonus::control()
{
	state = stay;
}

void HealthBonus::update(float time,float n1)
{
	if (life)
	{
		control();
		sprite.setTextureRect(IntRect(50, 175, SizeImgMap, SizeImgMap));
	} 
	sprite.setPosition(PosX, PosY);
}
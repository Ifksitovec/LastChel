//DamageBonus.cpp
#include "DamageBonus.h"

DamageBonus::DamageBonus(float x, float y)
{
	PrevState = east;//направляющее положение
	state = stay; // начальное положение
	hp = 300;
	PosX = x;
	PosY = y;
	speed = 0;
	type = BonusDam;
	CurrentFrame = 0;
	life = true;
	damage = 0;

	texture.loadFromFile("images/map.png");
	sprite.setTexture(texture);
	sprite.setPosition(PosX, PosY);
	sprite.setTextureRect(IntRect(100, 200, SizeImgMap, SizeImgMap));
}

bool DamageBonus::RadiusDamage(float x,float y)
{
	return true;
}

void DamageBonus::SetHp(int h, Gtype t)
{
	hp = hp;
}

void DamageBonus::control()
{
	state = stay;
}

void DamageBonus::update(float time,float n1)
{
	if (life)
	{
		control();
		sprite.setTextureRect(IntRect(100, 200, SizeImgMap, SizeImgMap));
	} 
	sprite.setPosition(PosX, PosY);
}
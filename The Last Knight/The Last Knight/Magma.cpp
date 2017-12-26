#include "Magma.h"

Magma::Magma(float x, float y)
{
	PrevState = east;//направляющее положение
	state = stay; // начальное положение
	hp = 300;
	PosX = x;
	PosY = y;
	speed = 0;
	type = magma;
	CurrentFrame = 0;
	life = true;
	damage = -1;

	texture.loadFromFile("images/map.png");
	sprite.setTexture(texture);
	sprite.setPosition(PosX, PosY);
	sprite.setTextureRect(IntRect(175, 225, SizeImgMap, SizeImgMap));
}

bool Magma::RadiusDamage(float x,float y)
{
	return true;
}

void Magma::SetHp(int h)
{
	hp = hp;
}

void Magma::control()
{
	state = stay;
}

void Magma::update(float time,float n1)
{
	if (life)
	{
		control();
		sprite.setTextureRect(IntRect(175, 225, SizeImgMap, SizeImgMap));
	} 
	sprite.setPosition(PosX, PosY);
}
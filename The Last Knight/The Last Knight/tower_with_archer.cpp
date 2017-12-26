#include "tower_with_archer.h"

TowerArch::TowerArch(float x, float y)
{
	PrevState = east;//направляющее положение
	state = stay; // начальное положение
	hp = 300;
	PosX = x;
	PosY = y;
	speed = 0;
	type = tow;
	CurrentFrame = 0;
	life = true;
	damage = 0;
	N = 0;

	texture.loadFromFile("images/orc_town.png");
	sprite.setTexture(texture);
	sprite.setPosition(PosX, PosY);
	sprite.setTextureRect(IntRect(484, 435, SizeImgTown, SizeImgTown));
}

bool TowerArch::RadiusDamage(float x,float y)
{
	if ((x - PosX) > 0) 
	{
		if ((x - PosX) > SizeImg) return true;
		else 
		{
			if ((y - PosY) > 0)
			{
				if ((y - PosY) > SizeImg) return true;
				else return false;
			}
			else
			{
				if ((PosY - y) > SizeImg) return true;
				else false;
			}
		}
	}
	else
	{
		if ((PosX - x) > SizeImg) return true;
		else 
		{
			if ((y - PosY) > 0)
			{
				if ((y - PosY) > SizeImg) return true;
				else return false;
			}
			else
			{
				if ((PosY - y) > SizeImg) return true;
				else false;
			}
		}
	}
}


void TowerArch::SetHp(int h)
{
	hp += h;
}

void TowerArch::control()
{
	state = stay;
}

void TowerArch::update(float time,float n1)
{
	if (life)
	{
		control();
		sprite.setTextureRect(IntRect(484, 435, SizeImgTown, SizeImgTown));

		if (hp <= 0)
		{ 
			life = false; 
			sprite.setTextureRect(IntRect(240, 432, SizeImgTown, SizeImgTown)); 
		}
	} 
	sprite.setPosition(PosX, PosY);
}
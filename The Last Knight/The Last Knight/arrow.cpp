#include "arrow.h"
#include <cmath>
using namespace std;

Arrow::Arrow(float x, float y)
{
	PrevState = east;//направл€ющее положение
	hp = 50;
	PosX = x;
	PosY = y;
	speed = 0.25;
	type = arrow;
	CurrentFrame = 0;
	life = true;
	damage = -20;
	N = 0;

	texture.loadFromFile("images/arm.png");
	sprite.setTexture(texture);
	sprite.setPosition(PosX, PosY);

	if (((int)(x - size/2) > 0) && ((int)(y - size/2) > 0)) //северо-запад
	{
		state = NorthWest;
		sprite.setTextureRect(IntRect(279, 12, SizeImgArr, SizeImgArr));
	}

	if (((int)(x - size/2) > 0) && ((int)(y - size/2) < 0)) //юго-запад
	{
		state = SouthWest;
		sprite.setTextureRect(IntRect(193, 14, SizeImgArr, SizeImgArr));
	}

	if (((int)(x - size/2) < 0) && ((int)(y - size/2) > 0)) //северо-восток
	{
		state = NorthEast;
		sprite.setTextureRect(IntRect(40, 14, SizeImgArr, SizeImgArr));
	}

	if (((int)(x - size/2) < 0) && ((int)(y - size/2) < 0)) //юго-восток
	{
		state = SouthEast;
		sprite.setTextureRect(IntRect(120, 17, SizeImgArr, SizeImgArr));
	}

	
	if (((int)(x - size/2) == 0) && ((int)(y - size/2) > 0)) //север
	{
		state = north;
		sprite.setTextureRect(IntRect(8, 10, SizeImgArr - 5, SizeImgArr + 5));
	}

	if (((int)(x - size/2) == 0) && ((int)(y - size/2) < 0)) //юг
	{
		state = south;
		sprite.setTextureRect(IntRect(158, 13, SizeImgArr - 5, SizeImgArr + 5));
	}

	if (((int)(x - size/2) < 0) && ((int)(y - size/2) == 0)) //восток
	{
		state = east;
		sprite.setTextureRect(IntRect(74, 18, SizeImgArr + 5, SizeImgArr - 5));
	}

	if (((int)(x - size/2) > 0) && ((int)(y - size/2) == 0)) //запад
	{
		state = west;
		sprite.setTextureRect(IntRect(233, 15, SizeImgArr + 5, SizeImgArr - 5));
	}
	
	switch (state)
	{
		case north:
		{
			dx = 0;
			dy = -speed;
			break;
		}

		case south:
		{
			dx = 0;
			dy = speed;
			break;
		}

		case west:
		{
			dx = -speed;
			dy = 0;
			break;
		}

		case east:
		{
			dx = speed;
			dy = 0;
			break;
		}

		case NorthWest:
		{
			dx = -speed * cos(atan((size/2 - y)/(size/2 - x)));
			dy = -speed * sin(atan((size/2 - y)/(size/2 - x)));
			break;
		}

		case NorthEast:
		{
			dx = speed * cos(atan((size/2 - y)/(x - size/2)));
			dy = -speed * sin(atan((size/2 - y)/(x - size/2)));
			break;
		}

		case SouthEast:
		{
			dx = speed * cos(atan((y - size/2)/(x - size/2)));
			dy = speed * sin(atan((y - size/2)/(x - size/2)));
			break;
		}

		case SouthWest:
		{
			dx = -speed * cos(atan((y - size/2)/(size/2 - x)));
			dy = speed * sin(atan((y - size/2)/(size/2 - x)));
			break;
		}
	}
}

void Arrow::SetHp(int h)
{
	hp = hp;
}

bool Arrow::RadiusDamage(float x,float y)
{
	return true;
}

void Arrow::control()
{
	state = state;
}

void Arrow::update(float time1,float n1)
{
	if (life)
	{
		if ((int)n1 == 0)
		{
			control();
			switch (state)
			{
				case north:
				{
					sprite.setTextureRect(IntRect(8, 10, SizeImgArr - 5, SizeImgArr + 5));
					break;
				}

				case south:
				{
					sprite.setTextureRect(IntRect(158, 13, SizeImgArr - 5, SizeImgArr + 5));
					break;
				}

				case east:
				{
					sprite.setTextureRect(IntRect(74, 18, SizeImgArr + 5, SizeImgArr - 5));
					break;
				}

				case west:
				{
					sprite.setTextureRect(IntRect(233, 15, SizeImgArr + 5, SizeImgArr - 5));
					break;
				}

				case NorthWest:
				{
					sprite.setTextureRect(IntRect(279, 12, SizeImgArr, SizeImgArr));
					break;
				}

				case NorthEast:
				{
					sprite.setTextureRect(IntRect(40, 14, SizeImgArr, SizeImgArr));
					break;
				}

				case SouthEast:
				{
					sprite.setTextureRect(IntRect(120, 17, SizeImgArr, SizeImgArr));
					break;
				}

				case SouthWest:
				{
					sprite.setTextureRect(IntRect(194, 13, SizeImgArr, SizeImgArr));
					break;
				}

			}
		}
		PosX += dx * time1; 
		PosY += dy * time1;
	}
	sprite.setPosition(PosX, PosY);
}
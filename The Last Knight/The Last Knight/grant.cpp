#include "grant.h"

Grant::Grant(float x, float y)
{
	PrevState = east;//направляющее положение
	state = stay; // начальное положение
	hp = 150;
	PosX = x;
	PosY = y;
	speed = 0.05;
	type = pers;
	CurrentFrame = 0;
	life = true;
	damage = -20;
	N = 0;

	texture.loadFromFile("images/grant.png");
	sprite.setTexture(texture);
	sprite.setPosition(PosX, PosY);
	sprite.setTextureRect(IntRect(36, 176, SizeImg - 15, SizeImg));
}

bool Grant::RadiusDamage(float x,float y)
{
	float dposX = x, dposY = y;
	int s = SizeImg - 20;
	if (life)
	{
		switch (PrevState)
		{
			case north:
			{
				if ((PosY - ((size + s)/2) ) < 15) return true;
				else false;
				break;
			}

			case west:
			{
				if ((PosX - ((size + s)/2) ) < 15) return true;
				else false;
				break;
			}

			case east:
			{
				if ((((size + 3 * s)/2) - PosX) < 15) return true;
				else false;
				break;
			}
		
			case south:
			{
				if ((((size + 3 * s)/2) - PosY) < 15) return true;
				else false;
				break;
			}

			case NorthEast:
			{
				if (((PosY - ((size + s)/2) ) < 15) && ((((size + 3 * s)/2) - PosX) < 15)) return true;
				else false;
				break;
			}

			case NorthWest:
			{
				if (((PosX - ((size + s)/2) ) < 15) && ((PosY - ((size + s)/2) ) < 15)) return true;
				else false;
				break;
			}

			case SouthEast:
			{
				if (((((size + 3 * s)/2) - PosX) < 15) && ((((size + 3 * s)/2) - PosY) < 15)) return true;
				else false;
				break;
			}
		
			case SouthWest:
			{
				if (((((size + 3 * s)/2) - PosY) < 15) && ((PosX - ((size + s)/2) ) < 15)) return true;
				else false;
				break;
			}
		}
	}
}

void Grant::SetHp(int h)
{
	hp += h;
}


//определеение направления движения
void Grant::control()
{ 
	float dposX = PosX - size/2, dposY = PosY - size/ 2;
	int s = SizeImg - 20;

	//Если объект достиг героя и стоит
	if (((state == attack) || (state == stay)) && (PosY <= (size + s)/2) && (PosY >= (size - 3 * s)/2) && (PosX <= (size + s)/2) && (PosX >= (size - 3 * s)/2))
	{
		state = attack;
	}
	else
	{
		if ((dposX > 0) && (dposY > 0) && (PosX > (size + s)/2) && (PosY > (size + s)/2))// если объект находится в правом нижнем углу
		{
			if (dposX > dposY) state = north;
			if (dposX < dposY) state = west;
			if (dposX == dposY) state = NorthWest;
		}

		if ((dposX > 0) && (dposY < 0) && (PosX > (size + s)/2) && (PosY < (size - 3 * s)/2))// если объект находится в правом верхнем углу
		{
			if (dposX > -dposY) state = south;
			if (dposX < -dposY) state = west;
			if (dposX == -dposY) state = SouthWest;
		}

		if ((dposX < 0) && (dposY > 0) && (PosX < (size - 3 * s)/2) && (PosY > (size + s)/2))// если объект находится в левом нижнем углу
		{
			if (-dposX > dposY) state = north;
			if (-dposX < dposY) state = east;
			if (-dposX == dposY) state = NorthEast;
		}

		if ((dposX < 0) && (dposY < 0) && (PosX < (size - 3 * s)/2) && (PosY < (size - 3 * s)/2))// если объект находится в правом нижнем углу
		{
			if (-dposX > -dposY) state = south;
			if (-dposX < -dposY) state = east;
			if (-dposX == -dposY) state = SouthEast;
		}

		if ((PosX <= (size + s)/2) && (PosX >= (size - 3 * s)/2))// если объект находится сверху или снизу от героя
		{
			if (dposY > 0) state = north;
			if (dposY < 0) state = south;
		}

		if ((PosY <= (size + s)/2) && (PosY >= (size - 3 * s)/2))// если объект находится справа или слева от героя
		{
			if (dposX > 0) state = west;
			if (dposX < 0) state = east;
		}

		if ((PosY <= (size + s)/2) && (PosY >= (size - 3 * s)/2) && (PosX <= (size + s)/2) && (PosX >= (size - 3 * s)/2)) state = stay; // если объект достиг героя
	}
}


//изменение движения
void Grant::update(float time,float n1)
{
	if (life)
	{
		control();
		if ((int)n1 == 0)
		{
			switch (state)
			{
				case west://движение налево
				{
					dx = -speed;
					dy = 0;
					CurrentFrame += 0.01 * time;
					if (CurrentFrame > 4) CurrentFrame -= 4;
					sprite.setTextureRect(IntRect(14 + 60 * int(CurrentFrame), 381, SizeImg +10, SizeImg));
					PrevState = west;
					break;
				}

				case north://движение вверх
				{
					dx = 0;
					dy = -speed;
					CurrentFrame += 0.01 * time;
					if (CurrentFrame > 4) CurrentFrame -= 4;
					sprite.setTextureRect(IntRect(60 * int(CurrentFrame), 0, SizeImg +10, SizeImg));
					PrevState = north;
					break;
				}

				case east://движение направо
				{
					dx = speed;
					dy = 0;
					CurrentFrame += 0.01 * time;
					if (CurrentFrame > 4) CurrentFrame -= 4;
					sprite.setTextureRect(IntRect(60 * int(CurrentFrame), 125, SizeImg + 10, SizeImg));
					PrevState = east;
					break;
				}

				case south://движение вниз
				{
					dx = 0;
					dy = speed;
					CurrentFrame += 0.01 * time;
					if (CurrentFrame > 4) CurrentFrame -= 4;
					sprite.setTextureRect(IntRect(60 * int(CurrentFrame), 252, SizeImg + 10, SizeImg));
					PrevState = south;
					break;
				}

				case NorthWest://движение вверх-налево
				{
					dx = -speed;
					dy = -speed;
					CurrentFrame += 0.01 * time;
					if (CurrentFrame > 4) CurrentFrame -= 4;
					sprite.setTextureRect(IntRect(6 + 61 * int(CurrentFrame), 446, SizeImg + 11, SizeImg));
					PrevState = NorthWest;
					break;
				}

				case NorthEast://движение вверх-направо
				{
					dx = speed;
					dy = -speed;
					CurrentFrame += 0.01 * time;
					if (CurrentFrame > 4) CurrentFrame -= 4;
					sprite.setTextureRect(IntRect(61 * int(CurrentFrame), 62, SizeImg + 11, SizeImg));
					PrevState = NorthEast;
					break;
				}

				case SouthEast://движение вниз-направо
				{
					dx = speed;
					dy = speed;
					CurrentFrame += 0.01 * time;
					if (CurrentFrame > 4) CurrentFrame -= 4;
					sprite.setTextureRect(IntRect(60 * int(CurrentFrame), 188, SizeImg + 10, SizeImg));
					PrevState = SouthEast;
					break;
				}

				case SouthWest://движение вниз-налево
				{
					dx = -speed;
					dy = speed;
					CurrentFrame += 0.01 * time;
					if (CurrentFrame > 4) CurrentFrame -= 4;
					sprite.setTextureRect(IntRect(11 + 60 * int(CurrentFrame), 315, SizeImg + 10, SizeImg));
					PrevState = SouthWest;
					break;
				}


				case stay://положение стоять в зависимости от того какое до этого было положение
				{
					CurrentFrame = 0;
					switch (PrevState)
					{
						case north:
						{	
							sprite.setTextureRect(IntRect(60 * int(CurrentFrame), 0, SizeImg +10, SizeImg));
							break;
						}

						case east:
						{	
							sprite.setTextureRect(IntRect(60 * int(CurrentFrame), 125, SizeImg + 10, SizeImg));
							break;
						}

						case west:
						{	
							sprite.setTextureRect(IntRect(14 + 60 * int(CurrentFrame), 381, SizeImg +10, SizeImg));
							break;
						}

						case south:
						{	
							sprite.setTextureRect(IntRect(60 * int(CurrentFrame), 252, SizeImg + 10, SizeImg));
							break;
						}

						case NorthWest:
						{	
							sprite.setTextureRect(IntRect(6 + 61 * int(CurrentFrame), 446, SizeImg + 11, SizeImg));
							break;
						}

						case NorthEast:
						{	
							sprite.setTextureRect(IntRect(61 * int(CurrentFrame), 62, SizeImg + 11, SizeImg));
							break;
						}

						case SouthWest:
						{	
							sprite.setTextureRect(IntRect(11 + 60 * int(CurrentFrame), 315, SizeImg + 10, SizeImg));
							break;
						}

						case SouthEast:
						{	
							sprite.setTextureRect(IntRect(60 * int(CurrentFrame), 188, SizeImg + 10, SizeImg));
							break;
						}
						
					}
					dx = 0;
					dy = 0;
				}
			}

		}
		else //отображение атаки
		{
			switch (PrevState)
					{
						case north:
						{	
							sprite.setTextureRect(IntRect(318 + 60 * int(n1), 0, SizeImg + 10, SizeImg));
							if ((int)n1 == 4) sprite.setTextureRect(IntRect(0, 0, SizeImg +10, SizeImg));
							break;
						}

						case east:
						{	
							sprite.setTextureRect(IntRect(314 + 63 * int(n1), 124, SizeImg + 13, SizeImg + 10));
							if ((int)n1 == 4) sprite.setTextureRect(IntRect(0, 125, SizeImg + 10, SizeImg));
							break;
						}

						case west:
						{	
							sprite.setTextureRect(IntRect(327 + 60 * int(n1), 380, SizeImg +10, SizeImg + 10));
							if ((int)n1 == 4) sprite.setTextureRect(IntRect(14, 381, SizeImg +10, SizeImg));
							break;
						}

						case south:
						{	
							sprite.setTextureRect(IntRect(310 + 63 * int(n1), 251, SizeImg + 13, SizeImg + 10));
							if ((int)n1 == 4) sprite.setTextureRect(IntRect(0, 252, SizeImg + 10, SizeImg));
							break;
						}

						case NorthWest:
						{	
							sprite.setTextureRect(IntRect(315 + 64 * int(n1), 445, SizeImg + 14, SizeImg));
							if ((int)n1 == 4) sprite.setTextureRect(IntRect(6, 446, SizeImg + 11, SizeImg));
							break;
						}

						case NorthEast:
						{	
							sprite.setTextureRect(IntRect(315 + 62 * int(n1), 61, SizeImg + 12, SizeImg));
							if ((int)n1 == 4) sprite.setTextureRect(IntRect(0, 62, SizeImg + 11, SizeImg));
							break;
						}

						case SouthWest:
						{	
							sprite.setTextureRect(IntRect(329 + 60 * int(n1), 315, SizeImg + 10, SizeImg + 10));
							if ((int)n1 == 4) sprite.setTextureRect(IntRect(11, 315, SizeImg + 10, SizeImg));
							break;
						}

						case SouthEast:
						{	
							sprite.setTextureRect(IntRect(308 + 65 * int(n1), 187, SizeImg + 15, SizeImg));
							if ((int)n1 == 4) sprite.setTextureRect(IntRect(0, 188, SizeImg + 10, SizeImg));
							break;
						}
						
					}
		dx = 0;
		dy = 0;
		}
		
		PosX += dx * time; 
		PosY += dy * time;
		//state = stay;
		if (hp <= 0)
		{ 
			life = false; 
			sprite.setTextureRect(IntRect(699, 254, SizeImg + 10, SizeImg + 3)); 
			dx = 0;
			dy = 0;
		}
	}
	sprite.setPosition(PosX, PosY);
}
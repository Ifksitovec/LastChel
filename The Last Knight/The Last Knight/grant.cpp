#include "grant.h"

Grant::Grant()
{
	prevstate = east;//направляющее положение
	state = stay; // начальное положение
	hp = 150;
	posX = 800;
	posY = 800;
	speed = 0.05;
	type = pers;
	CurrentFrame = 0;
	life = true;
	damage = -20;

	texture.loadFromFile("images/grant.png");
	sprite.setTexture(texture);
	sprite.setPosition(posX, posY);
	sprite.setTextureRect(IntRect(36, 176, size_img - 15, size_img));
}

bool Grant::radiusDamage(float x,float y)
{
	float dposX = x, dposY = y;
	int s = size_img - 20;
	if (life)
	{
		switch (prevstate)
		{
			case north:
			{
				if ((posY - ((size + s)/2) ) < 15) return true;
				else false;
				break;
			}

			case west:
			{
				if ((posX - ((size + s)/2) ) < 15) return true;
				else false;
				break;
			}

			case east:
			{
				if ((((size + 3 * s)/2) - posX) < 15) return true;
				else false;
				break;
			}
		
			case south:
			{
				if ((((size + 3 * s)/2) - posY) < 15) return true;
				else false;
				break;
			}

			case north_east:
			{
				if (((posY - ((size + s)/2) ) < 15) && ((((size + 3 * s)/2) - posX) < 15)) return true;
				else false;
				break;
			}

			case north_west:
			{
				if (((posX - ((size + s)/2) ) < 15) && ((posY - ((size + s)/2) ) < 15)) return true;
				else false;
				break;
			}

			case south_east:
			{
				if (((((size + 3 * s)/2) - posX) < 15) && ((((size + 3 * s)/2) - posY) < 15)) return true;
				else false;
				break;
			}
		
			case south_west:
			{
				if (((((size + 3 * s)/2) - posY) < 15) && ((posX - ((size + s)/2) ) < 15)) return true;
				else false;
				break;
			}
		}
	}
}

void Grant::setHP(int h)
{
	hp += h;
}


//определеение направления движения
void Grant::control()
{ 
	float dposX = posX - size/2, dposY = posY - size/ 2;
	int s = size_img - 20;

	//Если объект достиг героя и стоит
	if (((state == attack) || (state == stay)) && (posY <= (size + s)/2) && (posY >= (size - 3 * s)/2) && (posX <= (size + s)/2) && (posX >= (size - 3 * s)/2))
	{
		state = attack;
	}
	else
	{
		if ((dposX > 0) && (dposY > 0) && (posX > (size + s)/2) && (posY > (size + s)/2))// если объект находится в правом нижнем углу
		{
			if (dposX > dposY) state = north;
			if (dposX < dposY) state = west;
			if (dposX == dposY) state = north_west;
		}

		if ((dposX > 0) && (dposY < 0) && (posX > (size + s)/2) && (posY < (size - 3 * s)/2))// если объект находится в правом верхнем углу
		{
			if (dposX > -dposY) state = south;
			if (dposX < -dposY) state = west;
			if (dposX == -dposY) state = south_west;
		}

		if ((dposX < 0) && (dposY > 0) && (posX < (size - 3 * s)/2) && (posY > (size + s)/2))// если объект находится в левом нижнем углу
		{
			if (-dposX > dposY) state = north;
			if (-dposX < dposY) state = east;
			if (-dposX == dposY) state = north_east;
		}

		if ((dposX < 0) && (dposY < 0) && (posX < (size - 3 * s)/2) && (posY < (size - 3 * s)/2))// если объект находится в правом нижнем углу
		{
			if (-dposX > -dposY) state = south;
			if (-dposX < -dposY) state = east;
			if (-dposX == -dposY) state = south_east;
		}

		if ((posX <= (size + s)/2) && (posX >= (size - 3 * s)/2))// если объект находится сверху или снизу от героя
		{
			if (dposY > 0) state = north;
			if (dposY < 0) state = south;
		}

		if ((posY <= (size + s)/2) && (posY >= (size - 3 * s)/2))// если объект находится справа или слева от героя
		{
			if (dposX > 0) state = west;
			if (dposX < 0) state = east;
		}

		if ((posY <= (size + s)/2) && (posY >= (size - 3 * s)/2) && (posX <= (size + s)/2) && (posX >= (size - 3 * s)/2)) state = stay; // если объект достиг героя
	}
}


//изменение движения
void Grant::update(float time,float n)
{
	if (life)
	{
		control();
		if ((int)n == 0)
		{
			switch (state)
			{
				case west://движение налево
				{
					dx = -speed;
					dy = 0;
					CurrentFrame += 0.01 * time;
					if (CurrentFrame > 4) CurrentFrame -= 4;
					sprite.setTextureRect(IntRect(14 + 60 * int(CurrentFrame), 381, size_img +10, size_img));
					prevstate = west;
					break;
				}

				case north://движение вверх
				{
					dx = 0;
					dy = -speed;
					CurrentFrame += 0.01 * time;
					if (CurrentFrame > 4) CurrentFrame -= 4;
					sprite.setTextureRect(IntRect(60 * int(CurrentFrame), 0, size_img +10, size_img));
					prevstate = north;
					break;
				}

				case east://движение направо
				{
					dx = speed;
					dy = 0;
					CurrentFrame += 0.01 * time;
					if (CurrentFrame > 4) CurrentFrame -= 4;
					sprite.setTextureRect(IntRect(60 * int(CurrentFrame), 125, size_img + 10, size_img));
					prevstate = east;
					break;
				}

				case south://движение вниз
				{
					dx = 0;
					dy = speed;
					CurrentFrame += 0.01 * time;
					if (CurrentFrame > 4) CurrentFrame -= 4;
					sprite.setTextureRect(IntRect(60 * int(CurrentFrame), 252, size_img + 10, size_img));
					prevstate = south;
					break;
				}

				case north_west://движение вверх-налево
				{
					dx = -speed;
					dy = -speed;
					CurrentFrame += 0.01 * time;
					if (CurrentFrame > 4) CurrentFrame -= 4;
					sprite.setTextureRect(IntRect(6 + 61 * int(CurrentFrame), 446, size_img + 11, size_img));
					prevstate = north_west;
					break;
				}

				case north_east://движение вверх-направо
				{
					dx = speed;
					dy = -speed;
					CurrentFrame += 0.01 * time;
					if (CurrentFrame > 4) CurrentFrame -= 4;
					sprite.setTextureRect(IntRect(61 * int(CurrentFrame), 62, size_img + 11, size_img));
					prevstate = north_east;
					break;
				}

				case south_east://движение вниз-направо
				{
					dx = speed;
					dy = speed;
					CurrentFrame += 0.01 * time;
					if (CurrentFrame > 4) CurrentFrame -= 4;
					sprite.setTextureRect(IntRect(60 * int(CurrentFrame), 188, size_img + 10, size_img));
					prevstate = south_east;
					break;
				}

				case south_west://движение вниз-налево
				{
					dx = -speed;
					dy = speed;
					CurrentFrame += 0.01 * time;
					if (CurrentFrame > 4) CurrentFrame -= 4;
					sprite.setTextureRect(IntRect(11 + 60 * int(CurrentFrame), 315, size_img + 10, size_img));
					prevstate = south_west;
					break;
				}


				case stay://положение стоять в зависимости от того какое до этого было положение
				{
					CurrentFrame = 0;
					switch (prevstate)
					{
						case north:
						{	
							sprite.setTextureRect(IntRect(60 * int(CurrentFrame), 0, size_img +10, size_img));
							break;
						}

						case east:
						{	
							sprite.setTextureRect(IntRect(60 * int(CurrentFrame), 125, size_img + 10, size_img));
							break;
						}

						case west:
						{	
							sprite.setTextureRect(IntRect(14 + 60 * int(CurrentFrame), 381, size_img +10, size_img));
							break;
						}

						case south:
						{	
							sprite.setTextureRect(IntRect(60 * int(CurrentFrame), 252, size_img + 10, size_img));
							break;
						}

						case north_west:
						{	
							sprite.setTextureRect(IntRect(6 + 61 * int(CurrentFrame), 446, size_img + 11, size_img));
							break;
						}

						case north_east:
						{	
							sprite.setTextureRect(IntRect(61 * int(CurrentFrame), 62, size_img + 11, size_img));
							break;
						}

						case south_west:
						{	
							sprite.setTextureRect(IntRect(11 + 60 * int(CurrentFrame), 315, size_img + 10, size_img));
							break;
						}

						case south_east:
						{	
							sprite.setTextureRect(IntRect(60 * int(CurrentFrame), 188, size_img + 10, size_img));
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
			switch (prevstate)
					{
						case north:
						{	
							sprite.setTextureRect(IntRect(318 + 60 * int(n), 0, size_img + 10, size_img));
							if ((int)n == 4) sprite.setTextureRect(IntRect(0, 0, size_img +10, size_img));
							break;
						}

						case east:
						{	
							sprite.setTextureRect(IntRect(314 + 63 * int(n), 124, size_img + 13, size_img + 10));
							if ((int)n == 4) sprite.setTextureRect(IntRect(0, 125, size_img + 10, size_img));
							break;
						}

						case west:
						{	
							sprite.setTextureRect(IntRect(327 + 60 * int(n), 380, size_img +10, size_img + 10));
							if ((int)n == 4) sprite.setTextureRect(IntRect(14, 381, size_img +10, size_img));
							break;
						}

						case south:
						{	
							sprite.setTextureRect(IntRect(310 + 63 * int(n), 251, size_img + 13, size_img + 10));
							if ((int)n == 4) sprite.setTextureRect(IntRect(0, 252, size_img + 10, size_img));
							break;
						}

						case north_west:
						{	
							sprite.setTextureRect(IntRect(315 + 64 * int(n), 445, size_img + 14, size_img));
							if ((int)n == 4) sprite.setTextureRect(IntRect(6, 446, size_img + 11, size_img));
							break;
						}

						case north_east:
						{	
							sprite.setTextureRect(IntRect(315 + 62 * int(n), 61, size_img + 12, size_img));
							if ((int)n == 4) sprite.setTextureRect(IntRect(0, 62, size_img + 11, size_img));
							break;
						}

						case south_west:
						{	
							sprite.setTextureRect(IntRect(329 + 60 * int(n), 315, size_img + 10, size_img + 10));
							if ((int)n == 4) sprite.setTextureRect(IntRect(11, 315, size_img + 10, size_img));
							break;
						}

						case south_east:
						{	
							sprite.setTextureRect(IntRect(308 + 65 * int(n), 187, size_img + 15, size_img));
							if ((int)n == 4) sprite.setTextureRect(IntRect(0, 188, size_img + 10, size_img));
							break;
						}
						
					}
		dx = 0;
		dy = 0;
		}
		
		posX += dx * time; 
		posY += dy * time;
		//state = stay;
		if (hp <= 0)
		{ 
			life = false; 
			sprite.setTextureRect(IntRect(699, 254, size_img + 10, size_img + 3)); 
			dx = 0;
			dy = 0;
		}
	}
	sprite.setPosition(posX, posY);
}
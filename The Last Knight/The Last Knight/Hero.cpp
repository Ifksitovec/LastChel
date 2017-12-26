#include "Hero.h"

Hero::Hero() 
{
	PrevState = east;//направляющие положение
	state = stay; // начальное положение
	hp = 1000;
	PosX = (size - SizeImg) / 2;
	PosY = (size - SizeImg) / 2;
	speed = 0.1;
	type = pers;
	score = 0;
	CurrentFrame = 0;
	life = true;
	damage = -50;

	texture.loadFromFile("images/footman.png");
	sprite.setTexture(texture);
	sprite.setPosition(PosX, PosY);
	sprite.setTextureRect(IntRect(0, 127, SizeImg, SizeImg));
}

void Hero::SetHp(int h)
{
	if (state != block) hp += h;
}

bool Hero::RadiusDamage(float x, float y)// определение находится ли противник в зоне атаки
{
	switch (PrevState)
	{
		case north:
		{
			if ((x >= PosX - SizeImg) && (x <= PosX + 2 * SizeImg) && ((PosY - SizeImg/2  - y) < 25) & ((PosY - SizeImg/2  - y) > -25)) return true;
			else return false;
			break;
		}

		case west:
		{
			if ((y >= PosY - SizeImg) && (y <= PosY + 2 * SizeImg) && ((PosX - SizeImg/2  - x) < 25) && ((PosX - SizeImg/2  - x) > -25)) return true;
			else return false;
			break;
		}

		case east:
		{
			if ((y >= PosY - SizeImg) && (y <= PosY + 2 * SizeImg) && ((x - PosX - SizeImg/2) < 25) && ((x - PosX - SizeImg/2) > -25)) return true;
			else return false;
			break;
		}

		case south:
		{
			if ((x >= PosX - SizeImg) && (x <= PosX + 2 * SizeImg) && ((y - PosY - SizeImg/2) < 25) && ((y - PosY - SizeImg/2) > -25)) return true;
			else return false;
			break;
		}

		case NorthEast:
		{
			if (((x - PosX - SizeImg/2) < 25) && ((PosY - SizeImg/2  - y) < 25) && ((x - PosX - SizeImg/2) > -25) && ((PosY - SizeImg/2  - y) > -25)) return true;
			else return false;
			break;
		}

		case NorthWest:
		{
			if (((PosY - SizeImg/2  - y) < 25) && ((PosX - SizeImg/2  - x) < 25) && ((PosY - SizeImg/2  - y) > -25) && ((PosX - SizeImg/2  - x) > -25)) return true;
			else return false;
			break;
		}

		case SouthEast:
		{
			if (((y - PosY - SizeImg/2) < 25) && ((x - PosX - SizeImg/2) < 25) && ((y - PosY - SizeImg/2) > -25) && ((x - PosX - SizeImg/2) > -25)) return true;
			else return false;
			break;
		}

		case SouthWest:
		{
			if (((PosX - SizeImg/2/  - x) < 25) && ((y - PosY - SizeImg/2) < 25) && ((PosX - SizeImg/2  - x) > -25) && ((y - PosY - SizeImg/2) > -25)) return true;
			else return false;
			break;
		}
		default:
		{
			return false;
		}
	}
}

//действия по нажатию клавиш
void Hero::control()
{ 
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{ 
		state = west; 
	} 
	
	if (Keyboard::isKeyPressed(Keyboard::Right)) 
	{ 
		state = east; 
	} 
	
	if (Keyboard::isKeyPressed(Keyboard::Up)) 
	{ 
		state = north; 
	} 
	
	if (Keyboard::isKeyPressed(Keyboard::Down))
	{ 
		state = south; 
	} 

	if ((Keyboard::isKeyPressed(Keyboard::Down)) && (Keyboard::isKeyPressed(Keyboard::Left))) 
	{
		state = SouthWest;
	}
	
	if ((Keyboard::isKeyPressed(Keyboard::Down)) && (Keyboard::isKeyPressed(Keyboard::Right))) 
	{ 
		state = SouthEast; 
	} 

	if ((Keyboard::isKeyPressed(Keyboard::Up)) && (Keyboard::isKeyPressed(Keyboard::Left)))
	{ 
		state = NorthWest; 
	} 

	if ((Keyboard::isKeyPressed(Keyboard::Up)) && (Keyboard::isKeyPressed(Keyboard::Right)))
	{ 
		state = NorthEast; 
	} 

	if ((Keyboard::isKeyPressed(Keyboard::Left)) && (Keyboard::isKeyPressed(Keyboard::Right)))
	{ 
		state = stay; 
	} 

	if ((Keyboard::isKeyPressed(Keyboard::Up)) && (Keyboard::isKeyPressed(Keyboard::Down)))
	{ 
		state = stay; 
	} 

	if (Keyboard::isKeyPressed(Keyboard::Space))
	{ 
		state = attack; 
	} 

	if (Keyboard::isKeyPressed(Keyboard::LAlt))
	{ 
		state = block; 
	} 
}

//Изменение картинки персонажа
void Hero::update(float time, float n)
{
	if (life)
	{
		control();
		if (n == 0)
		{
			switch (state)
			{
			case east: //Движение вправо
				CurrentFrame +=0.01*time;
				if (CurrentFrame > 5) CurrentFrame -= 5;
				switch (int(CurrentFrame))
				{
					case 1:
					{
						sprite.setTextureRect(IntRect(0, 122, SizeImg, SizeImg));  
						break;
					}
					case 2:
					{
						sprite.setTextureRect(IntRect(60, 122, SizeImg, SizeImg));  
						break;
					}
					case 3:
					{
						sprite.setTextureRect(IntRect(122, 122, SizeImg, SizeImg));  
						break;
					}
					case 4:
					{
						sprite.setTextureRect(IntRect(185, 122, SizeImg, SizeImg));  
						break;
					}
					case 5:
					{
						sprite.setTextureRect(IntRect(248, 122, SizeImg, SizeImg));  
						break;
					}
				}
				PrevState = east;
				break; 

			case west: //Движение влево
				CurrentFrame +=0.01*time;
				if (CurrentFrame > 5) CurrentFrame -= 5;
				switch (int(CurrentFrame))
				{
					case 1:
					{
						sprite.setTextureRect(IntRect(5, 376, SizeImg, SizeImg));  
						break;
					}
					case 2:
					{
						sprite.setTextureRect(IntRect(65, 378, SizeImg, SizeImg));  
						break;
					}
					case 3:
					{
						sprite.setTextureRect(IntRect(127, 378, SizeImg, SizeImg));  
						break;
					}
					case 4:
					{
						sprite.setTextureRect(IntRect(197, 378, SizeImg, SizeImg));  
						break;
					}
					case 5:
					{
						sprite.setTextureRect(IntRect(257, 378, SizeImg, SizeImg));  
						break;
					}
				}
				PrevState = west;
				break;

			case north: //Движение вверх
				CurrentFrame +=0.01*time;
				if (CurrentFrame > 5) CurrentFrame -= 5;
				switch (int(CurrentFrame))
				{
					case 1:
					{
						sprite.setTextureRect(IntRect(0, 0, SizeImg, SizeImg));  
						break;
					}
					case 2:
					{
						sprite.setTextureRect(IntRect(58, 3, SizeImg, SizeImg));  
						break;
					}
					case 3:
					{
						sprite.setTextureRect(IntRect(117, 3, SizeImg, SizeImg));  
						break;
					}
					case 4:
					{
						sprite.setTextureRect(IntRect(183, 0, SizeImg, SizeImg));  
						break;
					}
					case 5:
					{
						sprite.setTextureRect(IntRect(248, 0, SizeImg, SizeImg));  
						break;
					}
				}
				PrevState = north;
				break;

			case south: //Движение вниз
				CurrentFrame +=0.01*time;
				if (CurrentFrame > 5) CurrentFrame -= 5;
				switch (int(CurrentFrame))
				{
					case 1:
					{
						sprite.setTextureRect(IntRect(0, 248, SizeImg, SizeImg));  
						break;
					}
					case 2:
					{
						sprite.setTextureRect(IntRect(58, 250, SizeImg, SizeImg));  
						break;
					}
					case 3:
					{
						sprite.setTextureRect(IntRect(117, 251, SizeImg, SizeImg));  
						break;
					}
					case 4:
					{
						sprite.setTextureRect(IntRect(185, 252, SizeImg, SizeImg));  
						break;
					}
					case 5:
					{
						sprite.setTextureRect(IntRect(250, 251, SizeImg, SizeImg));  
						break;
					}
				}
				PrevState = south;
				break;

			case NorthEast: //Движение вверх-вправо 
				CurrentFrame +=0.01*time;
				if (CurrentFrame > 5) CurrentFrame -= 5;
				switch (int(CurrentFrame))
				{
					case 1:
					{
						sprite.setTextureRect(IntRect(0, 58, SizeImg, SizeImg));  
						break;
					}
					case 2:
					{
						sprite.setTextureRect(IntRect(57, 59, SizeImg, SizeImg));  
						break;
					}
					case 3:
					{
						sprite.setTextureRect(IntRect(121, 61, SizeImg, SizeImg));  
						break;
					}
					case 4:
					{
						sprite.setTextureRect(IntRect(183, 57, SizeImg, SizeImg));  
						break;
					}
					case 5:
					{
						sprite.setTextureRect(IntRect(248, 59, SizeImg, SizeImg));  
						break;
					}
				}
				PrevState = NorthEast;
				break; 

			case NorthWest: //Движение вверх-влево 
				CurrentFrame +=0.01*time;
				if (CurrentFrame > 5) CurrentFrame -= 5;
				switch (int(CurrentFrame))
				{
					case 1:
					{
						sprite.setTextureRect(IntRect(5, 442, SizeImg, SizeImg));  
						break;
					}
					case 2:
					{
						sprite.setTextureRect(IntRect(62, 443, SizeImg, SizeImg));  
						break;
					}
					case 3:
					{
						sprite.setTextureRect(IntRect(132, 443, SizeImg, SizeImg));  
						break;
					}
					case 4:
					{
						sprite.setTextureRect(IntRect(196, 443, SizeImg, SizeImg));  
						break;
					}
					case 5:
					{
						sprite.setTextureRect(IntRect(262, 439, SizeImg, SizeImg));  
						break;
					}
				}
				PrevState = NorthWest;
				break; 

			case SouthEast: //Движение вниз-вправо
				CurrentFrame +=0.01*time;
				if (CurrentFrame > 5) CurrentFrame -= 5;
				switch (int(CurrentFrame))
				{
					case 1:
					{
						sprite.setTextureRect(IntRect(0, 185, SizeImg, SizeImg));  
						break;
					}
					case 2:
					{
						sprite.setTextureRect(IntRect(57, 187, SizeImg, SizeImg));  
						break;
					}
					case 3:
					{
						sprite.setTextureRect(IntRect(120, 185, SizeImg, SizeImg));  
						break;
					}
					case 4:
					{
						sprite.setTextureRect(IntRect(185, 185, SizeImg, SizeImg));  
						break;
					}
					case 5:
					{
						sprite.setTextureRect(IntRect(249, 185, SizeImg, SizeImg));  
						break;
					}
				}
				PrevState = SouthEast;
				break; 
			case SouthWest: //Движение вниз-влево

				CurrentFrame +=0.01*time;
				if (CurrentFrame > 5) CurrentFrame -= 5;
				switch (int(CurrentFrame))
				{
					case 1:
					{
						sprite.setTextureRect(IntRect(0, 313, SizeImg, SizeImg));  
						break;
					}
					case 2:
					{
						sprite.setTextureRect(IntRect(59, 315, SizeImg, SizeImg));  
						break;
					}
					case 3:
					{
						sprite.setTextureRect(IntRect(127, 315, SizeImg, SizeImg));  
						break;
					}
					case 4:
					{
						sprite.setTextureRect(IntRect(191, 313, SizeImg, SizeImg));  
						break;
					}
					case 5:
					{
						sprite.setTextureRect(IntRect(256, 313, SizeImg, SizeImg));  
						break;
					}
				}
				PrevState = SouthWest;
				break; 

			case block: // блокировка
			{	
				switch (PrevState)
				{
					case north:
					{
						sprite.setTextureRect(IntRect(377, 0, SizeImg, SizeImg)); 
						break;
					}
					
					case west:
					{
						sprite.setTextureRect(IntRect(368, 380, SizeImg + 10, SizeImg)); 
						break;
					}

					case east:
					{
						sprite.setTextureRect(IntRect(383, 125, SizeImg + 10, SizeImg)); 
						break;
					}

					case south:
					{
						sprite.setTextureRect(IntRect(330, 318, SizeImg - 10, SizeImg)); 
						break;
					}

					case NorthWest:
					{
						sprite.setTextureRect(IntRect(374, 446, SizeImg, SizeImg)); 
						break;
					}

					case NorthEast:
					{
						sprite.setTextureRect(IntRect(385, 61, SizeImg, SizeImg)); 
						break;
					}

					case SouthWest:
					{
						sprite.setTextureRect(IntRect(315, 251, SizeImg, SizeImg)); 
						break;
					}

					case SouthEast:
					{
						sprite.setTextureRect(IntRect(381, 192, SizeImg - 10, SizeImg)); 
						break;
					}
				}

				break;
			}
			}
		}
		else
		{
			switch (PrevState )
			{
				case east://изображение атаки при направлении направо
				{
					switch (int(n))
					{
						case 0:
						{
							sprite.setTextureRect(IntRect(314, 127, SizeImg, SizeImg));  
							break;
						}
						case 1:
						{
							sprite.setTextureRect(IntRect(384, 126, SizeImg+10, SizeImg));  
							break;
						}
						case 2:
						{
							sprite.setTextureRect(IntRect(443, 126, SizeImg, SizeImg+5));  
							break;
						}
						case 3:
						{
							sprite.setTextureRect(IntRect(510, 126, SizeImg+10, SizeImg));  
							break;
						}
						case 4:
						{
							sprite.setTextureRect(IntRect(0, 120, SizeImg, SizeImg));  
							break;
						}
					}
				break;
				}

				case west://изображение атаки при направлении налево
				{
					switch (int(n))
					{
						case 0:
						{
							sprite.setTextureRect(IntRect(327, 384, SizeImg - 10,SizeImg));  
							break;
						}
						case 1:
						{
							sprite.setTextureRect(IntRect(360, 380, SizeImg+10, SizeImg));  
							break;
						}
						case 2:
						{
							sprite.setTextureRect(IntRect(443, 384, SizeImg, SizeImg+5));  
							break;
						}
						case 3:
						{
							sprite.setTextureRect(IntRect(507, 380, SizeImg, SizeImg-10));  
							break;
						}
						case 4:
						{
							sprite.setTextureRect(IntRect(5, 376, SizeImg, SizeImg));  
							break;
						}
					}
				break;
				}

				case north://изображение атаки при направлении вверх
				{
					switch (int(n))
					{
						case 0:
						{
							sprite.setTextureRect(IntRect(320, 0, SizeImg, SizeImg - 10));  
							break;
						}
						case 1:
						{
							sprite.setTextureRect(IntRect(382, 0, SizeImg - 10, SizeImg + 10));  
							break;
						}
						case 2:
						{
							sprite.setTextureRect(IntRect(446, 0, SizeImg + 10, SizeImg - 10));  
							break;
						}
						case 3:
						{
							sprite.setTextureRect(IntRect(505, 0, SizeImg - 10, SizeImg));  
							break;
						}
						case 4:
						{
							sprite.setTextureRect(IntRect(0, 0, SizeImg, SizeImg));
							break;
						}
					}
				break;
				}

				case south://изображение атаки при направлении вниз
				{
					switch (int(n))
					{
						case 0:
						{
							sprite.setTextureRect(IntRect(310, 252, SizeImg + 10, SizeImg));  
							break;
						}
						case 1:
						{
							sprite.setTextureRect(IntRect(380, 254, SizeImg, SizeImg - 10));  
							break;
						}
						case 2:
						{
							sprite.setTextureRect(IntRect(440, 246, SizeImg + 10, SizeImg));  
							break;
						}
						case 3:
						{
							sprite.setTextureRect(IntRect(508, 249, SizeImg - 10, SizeImg + 10));  
							break;
						}
						case 4:
						{
							sprite.setTextureRect(IntRect(0, 248, SizeImg, SizeImg)); 
							break;
						}
					}
				break;
				}

				case SouthEast://изображение атаки при направлении вниз-вправо
				{
					switch (int(n))
					{
						case 0:
						{
							sprite.setTextureRect(IntRect(311, 189, SizeImg + 10, SizeImg - 10));  
							break;
						}
						case 1:
						{
							sprite.setTextureRect(IntRect(375, 188, SizeImg, SizeImg + 10));  
							break;
						}
						case 2:
						{
							sprite.setTextureRect(IntRect(436, 190, SizeImg + 10, SizeImg));  
							break;
						}
						case 3:
						{
							sprite.setTextureRect(IntRect(505, 184, SizeImg + 20, SizeImg));  
							break;
						}
						case 4:
						{
							sprite.setTextureRect(IntRect(0, 185, SizeImg, SizeImg));
							break;
						}
					}
				break;
				}

				case SouthWest://изображение атаки при направлении вниз-влево
				{
					switch (int(n))
					{
						case 0:
						{
							sprite.setTextureRect(IntRect(331, 316, SizeImg - 10, SizeImg + 10));  
							break;
						}
						case 1:
						{
							sprite.setTextureRect(IntRect(383, 319, SizeImg, SizeImg + 10));  
							break;
						}
						case 2:
						{
							sprite.setTextureRect(IntRect(448, 317, SizeImg - 5, SizeImg + 10));  
							break;
						}
						case 3:
						{
							sprite.setTextureRect(IntRect(491, 315, SizeImg + 20, SizeImg));  
							break;
						}
						case 4:
						{
							sprite.setTextureRect(IntRect(0, 313, SizeImg, SizeImg));
							break;
						}
					}
				break;
				}

				case NorthEast://изображение атаки при направлении вверх-вправо
				{
					switch (int(n))
					{
						case 0:
						{
							sprite.setTextureRect(IntRect(317, 60, SizeImg + 15, SizeImg));  
							break;
						}
						case 1:
						{
							sprite.setTextureRect(IntRect(383, 62, SizeImg+10, SizeImg));  
							break;
						}
						case 2:
						{
							sprite.setTextureRect(IntRect(444, 58, SizeImg + 10, SizeImg + 10));  
							break;
						}
						case 3:
						{
							sprite.setTextureRect(IntRect(505, 63, SizeImg, SizeImg));  
							break;
						}
						case 4:
						{
							sprite.setTextureRect(IntRect(0, 58, SizeImg, SizeImg));  
							break;
						}
					}
				break;
				}

				case NorthWest://изображение атаки при направлении вверх-влево
				{
					switch (int(n))
					{
						case 0:
						{
							sprite.setTextureRect(IntRect(306, 445, SizeImg + 10, SizeImg));  
							break;
						}
						case 1:
						{
							sprite.setTextureRect(IntRect(369, 445, SizeImg + 10, SizeImg));  
							break;
						}
						case 2:
						{
							sprite.setTextureRect(IntRect(429, 448, SizeImg + 10, SizeImg));  
							break;
						}
						case 3:
						{
							sprite.setTextureRect(IntRect(505, 446, SizeImg + 20, SizeImg));  
							break;
						}
						case 4:
						{
							sprite.setTextureRect(IntRect(5, 442, SizeImg, SizeImg)); 
							break;
						}
					}
				break;
				}
			}
		}
		
		if (hp <= 0)
		{ 
			life = false; 
			sprite.setTextureRect(IntRect(700, 188, SizeImg, SizeImg)); 
		}
		sprite.setPosition(PosX, PosY);
	}
}
#include "Hero.h"

Hero::Hero() 
{
	prevstate = east;//направляющие положение
	state = stay; // начальное положение
	hp = 100;
	posX = (size - size_img) / 2;
	posY = (size - size_img) / 2;
	speed = 0.1;
	type = pers;
	score = 0;
	CurrentFrame = 0;
	life = true;
	damage = -50;

	texture.loadFromFile("images/footman.png");
	sprite.setTexture(texture);
	sprite.setPosition(posX, posY);
	sprite.setTextureRect(IntRect(0, 127, size_img, size_img));
}

void Hero::setHP(int h)
{
	if (state != block) hp += h;
}

bool Hero::radiusDamage(float x, float y)
{
	switch (prevstate)
	{
		case north:
		{
			if ((x >= posX - size_img) && (x <= posX + 2 * size_img) && ((posY - size_img/2  - y) < 15)) return true;
			else return false;
			break;
		}

		case west:
		{
			if ((y >= posY - size_img) && (y <= posY + 2 * size_img) && ((posX - size_img/2  - x) < 15)) return true;
			else return false;
			break;
		}

		case east:
		{
			if ((y >= posY - size_img) && (y <= posY + 2 * size_img) && ((x - posX - size_img/2) < 15)) return true;
			else return false;
			break;
		}

		case south:
		{
			if ((x >= posX - size_img) && (x <= posX + 2 * size_img) && ((y - posY - size_img/2) < 15)) return true;
			else return false;
			break;
		}

		case north_east:
		{
			if (((x - posX - size_img/2) < 15) && ((posY - size_img/2  - y) < 15)) return true;
			else return false;
			break;
		}

		case north_west:
		{
			if (((posY - size_img/2  - y) < 15) && ((posX - size_img/2  - x) < 15)) return true;
			else return false;
			break;
		}

		case south_east:
		{
			if (((y - posY - size_img/2) < 15) && ((x - posX - size_img/2) < 15)) return true;
			else return false;
			break;
		}

		case south_west:
		{
			if (((posX - size_img/2  - x) < 15) && ((y - posY - size_img/2) < 15)) return true;
			else return false;
			break;
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
		state = south_west;
	}
	
	if ((Keyboard::isKeyPressed(Keyboard::Down)) && (Keyboard::isKeyPressed(Keyboard::Right))) 
	{ 
		state = south_east; 
	} 

	if ((Keyboard::isKeyPressed(Keyboard::Up)) && (Keyboard::isKeyPressed(Keyboard::Left)))
	{ 
		state = north_west; 
	} 

	if ((Keyboard::isKeyPressed(Keyboard::Up)) && (Keyboard::isKeyPressed(Keyboard::Right)))
	{ 
		state = north_east; 
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
						sprite.setTextureRect(IntRect(0, 122, size_img, size_img));  
						break;
					}
					case 2:
					{
						sprite.setTextureRect(IntRect(60, 122, size_img, size_img));  
						break;
					}
					case 3:
					{
						sprite.setTextureRect(IntRect(122, 122, size_img, size_img));  
						break;
					}
					case 4:
					{
						sprite.setTextureRect(IntRect(185, 122, size_img, size_img));  
						break;
					}
					case 5:
					{
						sprite.setTextureRect(IntRect(248, 122, size_img, size_img));  
						break;
					}
				}
				prevstate = east;
				break; 

			case west: //Движение влево
				CurrentFrame +=0.01*time;
				if (CurrentFrame > 5) CurrentFrame -= 5;
				switch (int(CurrentFrame))
				{
					case 1:
					{
						sprite.setTextureRect(IntRect(5, 376, size_img, size_img));  
						break;
					}
					case 2:
					{
						sprite.setTextureRect(IntRect(65, 378, size_img, size_img));  
						break;
					}
					case 3:
					{
						sprite.setTextureRect(IntRect(127, 378, size_img, size_img));  
						break;
					}
					case 4:
					{
						sprite.setTextureRect(IntRect(197, 378, size_img, size_img));  
						break;
					}
					case 5:
					{
						sprite.setTextureRect(IntRect(257, 378, size_img, size_img));  
						break;
					}
				}
				prevstate = west;
				break;

			case north: //Движение вверх
				CurrentFrame +=0.01*time;
				if (CurrentFrame > 5) CurrentFrame -= 5;
				switch (int(CurrentFrame))
				{
					case 1:
					{
						sprite.setTextureRect(IntRect(0, 0, size_img, size_img));  
						break;
					}
					case 2:
					{
						sprite.setTextureRect(IntRect(58, 3, size_img, size_img));  
						break;
					}
					case 3:
					{
						sprite.setTextureRect(IntRect(117, 3, size_img, size_img));  
						break;
					}
					case 4:
					{
						sprite.setTextureRect(IntRect(183, 0, size_img, size_img));  
						break;
					}
					case 5:
					{
						sprite.setTextureRect(IntRect(248, 0, size_img, size_img));  
						break;
					}
				}
				prevstate = north;
				break;

			case south: //Движение вниз
				CurrentFrame +=0.01*time;
				if (CurrentFrame > 5) CurrentFrame -= 5;
				switch (int(CurrentFrame))
				{
					case 1:
					{
						sprite.setTextureRect(IntRect(0, 248, size_img, size_img));  
						break;
					}
					case 2:
					{
						sprite.setTextureRect(IntRect(58, 250, size_img, size_img));  
						break;
					}
					case 3:
					{
						sprite.setTextureRect(IntRect(117, 251, size_img, size_img));  
						break;
					}
					case 4:
					{
						sprite.setTextureRect(IntRect(185, 252, size_img, size_img));  
						break;
					}
					case 5:
					{
						sprite.setTextureRect(IntRect(250, 251, size_img, size_img));  
						break;
					}
				}
				prevstate = south;
				break;

			case north_east: //Движение вверх-вправо 
				CurrentFrame +=0.01*time;
				if (CurrentFrame > 5) CurrentFrame -= 5;
				switch (int(CurrentFrame))
				{
					case 1:
					{
						sprite.setTextureRect(IntRect(0, 58, size_img, size_img));  
						break;
					}
					case 2:
					{
						sprite.setTextureRect(IntRect(57, 59, size_img, size_img));  
						break;
					}
					case 3:
					{
						sprite.setTextureRect(IntRect(121, 61, size_img, size_img));  
						break;
					}
					case 4:
					{
						sprite.setTextureRect(IntRect(183, 57, size_img, size_img));  
						break;
					}
					case 5:
					{
						sprite.setTextureRect(IntRect(248, 59, size_img, size_img));  
						break;
					}
				}
				prevstate = north_east;
				break; 

			case north_west: //Движение вверх-влево 
				CurrentFrame +=0.01*time;
				if (CurrentFrame > 5) CurrentFrame -= 5;
				switch (int(CurrentFrame))
				{
					case 1:
					{
						sprite.setTextureRect(IntRect(5, 442, size_img, size_img));  
						break;
					}
					case 2:
					{
						sprite.setTextureRect(IntRect(62, 443, size_img, size_img));  
						break;
					}
					case 3:
					{
						sprite.setTextureRect(IntRect(132, 443, size_img, size_img));  
						break;
					}
					case 4:
					{
						sprite.setTextureRect(IntRect(196, 443, size_img, size_img));  
						break;
					}
					case 5:
					{
						sprite.setTextureRect(IntRect(262, 439, size_img, size_img));  
						break;
					}
				}
				prevstate = north_west;
				break; 

			case south_east: //Движение вниз-вправо
				CurrentFrame +=0.01*time;
				if (CurrentFrame > 5) CurrentFrame -= 5;
				switch (int(CurrentFrame))
				{
					case 1:
					{
						sprite.setTextureRect(IntRect(0, 185, size_img, size_img));  
						break;
					}
					case 2:
					{
						sprite.setTextureRect(IntRect(57, 187, size_img, size_img));  
						break;
					}
					case 3:
					{
						sprite.setTextureRect(IntRect(120, 185, size_img, size_img));  
						break;
					}
					case 4:
					{
						sprite.setTextureRect(IntRect(185, 185, size_img, size_img));  
						break;
					}
					case 5:
					{
						sprite.setTextureRect(IntRect(249, 185, size_img, size_img));  
						break;
					}
				}
				prevstate = south_east;
				break; 
			case south_west: //Движение вниз-влево

				CurrentFrame +=0.01*time;
				if (CurrentFrame > 5) CurrentFrame -= 5;
				switch (int(CurrentFrame))
				{
					case 1:
					{
						sprite.setTextureRect(IntRect(0, 313, size_img, size_img));  
						break;
					}
					case 2:
					{
						sprite.setTextureRect(IntRect(59, 315, size_img, size_img));  
						break;
					}
					case 3:
					{
						sprite.setTextureRect(IntRect(127, 315, size_img, size_img));  
						break;
					}
					case 4:
					{
						sprite.setTextureRect(IntRect(191, 313, size_img, size_img));  
						break;
					}
					case 5:
					{
						sprite.setTextureRect(IntRect(256, 313, size_img, size_img));  
						break;
					}
				}
				prevstate = south_west;
				break; 
			}
		}
		else
		{
			switch (prevstate )
			{
				case east://изображение атаки при направлении направо
				{
					switch (int(n))
					{
						case 0:
						{
							sprite.setTextureRect(IntRect(314, 127, size_img, size_img));  
							break;
						}
						case 1:
						{
							sprite.setTextureRect(IntRect(384, 126, size_img+10, size_img));  
							break;
						}
						case 2:
						{
							sprite.setTextureRect(IntRect(443, 126, size_img, size_img+5));  
							break;
						}
						case 3:
						{
							sprite.setTextureRect(IntRect(510, 126, size_img+10, size_img));  
							break;
						}
						case 4:
						{
							sprite.setTextureRect(IntRect(0, 120, size_img, size_img));  
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
							sprite.setTextureRect(IntRect(327, 384, size_img - 10,size_img));  
							break;
						}
						case 1:
						{
							sprite.setTextureRect(IntRect(360, 380, size_img+10, size_img));  
							break;
						}
						case 2:
						{
							sprite.setTextureRect(IntRect(443, 384, size_img, size_img+5));  
							break;
						}
						case 3:
						{
							sprite.setTextureRect(IntRect(507, 380, size_img, size_img-10));  
							break;
						}
						case 4:
						{
							sprite.setTextureRect(IntRect(5, 376, size_img, size_img));  
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
							sprite.setTextureRect(IntRect(320, 0, size_img, size_img - 10));  
							break;
						}
						case 1:
						{
							sprite.setTextureRect(IntRect(382, 0, size_img - 10, size_img + 10));  
							break;
						}
						case 2:
						{
							sprite.setTextureRect(IntRect(446, 0, size_img + 10, size_img - 10));  
							break;
						}
						case 3:
						{
							sprite.setTextureRect(IntRect(505, 0, size_img - 10, size_img));  
							break;
						}
						case 4:
						{
							sprite.setTextureRect(IntRect(0, 0, size_img, size_img));
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
							sprite.setTextureRect(IntRect(310, 252, size_img + 10, size_img));  
							break;
						}
						case 1:
						{
							sprite.setTextureRect(IntRect(380, 254, size_img, size_img - 10));  
							break;
						}
						case 2:
						{
							sprite.setTextureRect(IntRect(440, 246, size_img + 10, size_img));  
							break;
						}
						case 3:
						{
							sprite.setTextureRect(IntRect(508, 249, size_img - 10, size_img + 10));  
							break;
						}
						case 4:
						{
							sprite.setTextureRect(IntRect(0, 248, size_img, size_img)); 
							break;
						}
					}
				break;
				}

				case south_east://изображение атаки при направлении вниз-вправо
				{
					switch (int(n))
					{
						case 0:
						{
							sprite.setTextureRect(IntRect(311, 189, size_img + 10, size_img - 10));  
							break;
						}
						case 1:
						{
							sprite.setTextureRect(IntRect(375, 188, size_img, size_img + 10));  
							break;
						}
						case 2:
						{
							sprite.setTextureRect(IntRect(436, 190, size_img + 10, size_img));  
							break;
						}
						case 3:
						{
							sprite.setTextureRect(IntRect(505, 184, size_img + 20, size_img));  
							break;
						}
						case 4:
						{
							sprite.setTextureRect(IntRect(0, 185, size_img, size_img));
							break;
						}
					}
				break;
				}

				case south_west://изображение атаки при направлении вниз-влево
				{
					switch (int(n))
					{
						case 0:
						{
							sprite.setTextureRect(IntRect(331, 316, size_img - 10, size_img + 10));  
							break;
						}
						case 1:
						{
							sprite.setTextureRect(IntRect(383, 319, size_img, size_img + 10));  
							break;
						}
						case 2:
						{
							sprite.setTextureRect(IntRect(448, 317, size_img - 5, size_img + 10));  
							break;
						}
						case 3:
						{
							sprite.setTextureRect(IntRect(491, 315, size_img + 20, size_img));  
							break;
						}
						case 4:
						{
							sprite.setTextureRect(IntRect(0, 313, size_img, size_img));
							break;
						}
					}
				break;
				}

				case north_east://изображение атаки при направлении вверх-вправо
				{
					switch (int(n))
					{
						case 0:
						{
							sprite.setTextureRect(IntRect(317, 60, size_img + 15, size_img));  
							break;
						}
						case 1:
						{
							sprite.setTextureRect(IntRect(383, 62, size_img+10, size_img));  
							break;
						}
						case 2:
						{
							sprite.setTextureRect(IntRect(444, 58, size_img + 10, size_img + 10));  
							break;
						}
						case 3:
						{
							sprite.setTextureRect(IntRect(505, 63, size_img, size_img));  
							break;
						}
						case 4:
						{
							sprite.setTextureRect(IntRect(0, 58, size_img, size_img));  
							break;
						}
					}
				break;
				}

				case north_west://изображение атаки при направлении вверх-влево
				{
					switch (int(n))
					{
						case 0:
						{
							sprite.setTextureRect(IntRect(306, 445, size_img + 10, size_img));  
							break;
						}
						case 1:
						{
							sprite.setTextureRect(IntRect(369, 445, size_img + 10, size_img));  
							break;
						}
						case 2:
						{
							sprite.setTextureRect(IntRect(429, 448, size_img + 10, size_img));  
							break;
						}
						case 3:
						{
							sprite.setTextureRect(IntRect(505, 446, size_img + 20, size_img));  
							break;
						}
						case 4:
						{
							sprite.setTextureRect(IntRect(5, 442, size_img, size_img)); 
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
			sprite.setTextureRect(IntRect(700, 188, size_img, size_img)); 
		}
		sprite.setPosition(posX, posY);
	}
}
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

	texture.loadFromFile("images/footman.png");
	sprite.setTexture(texture);
	sprite.setPosition(posX, posY);
	sprite.setTextureRect(IntRect(0, 127, size_img, size_img));
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
}

//Изменение картинки персонажа
void Hero::update(float time, float n)
{
	if (life)
	{
		control();
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
		case attack: // движение для атаки
			CurrentFrame = n;
			if (prevstate == east)
			{
				switch (int(CurrentFrame))
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
				}
			}
		sprite.setPosition(posX, posY);

		if (hp <= 0)
		{ 
			life = false; 
		}
		}
	}
}
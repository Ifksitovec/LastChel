#include <SFML/Graphics.hpp>
#include <iostream>
#include "Hero.h"
#include "globals.h"
#include "MapCreator.h"
#include "grant.h"
#include <list>
#include <sstream>
#include "TowerWithArcher.h"
#include "arrow.h"
#include "HealthBonus.h"
#include "DamageBonus.h"
#include "Magma.h"

using namespace sf;
using namespace std; 

extern char TileMap[HeightMap][HeightMap];

int main()
{
	Hero hero;
	Clock clock;
	Clock clock2;
	Clock gameTimeClock;//переменная игрового времени, будем здесь хранить время игры 
	int gameTime = 0;//объявили игровое время, инициализировали.

	Font font;
	font.loadFromFile("CyrilicOld.TTF");
	Text TextHp("", font, 40);
	TextHp.setColor(Color::Green);
	Text TextScore("", font, 40);
	TextScore.setColor(Color::Green);
	Text TextLose("", font, 100);
	TextLose.setColor(Color::Red);
	Text TextLose1("", font, 102);
	TextLose.setColor(Color::Black);

	std::list<Entity*> enemy;
	std::list<Entity*>::iterator ItEnemy;

	std::list<Arrow*> arrow;
	std::list<Arrow*>::iterator ItArrow;
	Image MapImage;
	MapImage.loadFromFile("images/map.png");
	Texture map;
	map.loadFromImage(MapImage);//заряжаем текстуру картинкой
	Sprite SpriteMap;//создаём спрайт для карты
	SpriteMap.setTexture(map);//заливаем текстуру спрайтом

	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	sf::RenderWindow window(sf::VideoMode(size, size, desktop.bitsPerPixel), "The Last Knight");

	RandomMapGenerate();

	while (window.isOpen())  //Пока окно открыто
	{
		static float n = 0;
		int x = -50, y = -50;
		float dx1 = 0, dy1 = 0;
		float MapSpeed = 10*hero.GetSpeed();
		static float x1 = 0, y1 = 0;
		Gstate status = hero.GetState();

		float time = clock.getElapsedTime().asMicroseconds();
		float AttackTime = clock2.getElapsedTime().asMilliseconds();
		if (hero.GetLife()) gameTime = gameTimeClock.getElapsedTime().asSeconds();
			//игровое время в секундах идёт вперед, пока жив игрок. 

		clock.restart();
		time = time / 800;
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}


		
		if ((int)n == 0) 
		{
			if ((hero.GetState() == attack) && (hero.GetLife()) && (AttackTime >= delay / 3))
			{
				clock2.restart();
				n += 0.01*time;
			}
			else
			{
				switch (status)// установление изменения карты в зависимости от движения
				{
					case north:
					{	
						dx1 = 0;
						dy1 = MapSpeed;
						break;
					}
					case west:
					{	
						dx1 = MapSpeed;
						dy1 = 0;
						break;
					}
					case east:
					{	
						dx1 = -MapSpeed;
						dy1 = 0;
						break;
					}
					case south:
					{	
						dx1 = 0;
						dy1 = -MapSpeed;
						break;
					}
					case NorthWest:
					{	
						dx1 = MapSpeed;
						dy1 = MapSpeed;
						break;
					}
					case NorthEast:
					{	
						dx1 = -MapSpeed;
						dy1 = MapSpeed;
						break;
					}
					case SouthWest:
					{	
						dx1 = MapSpeed;
						dy1 = -MapSpeed;
						break;
					}
					case SouthEast:
					{	
						dx1 = -MapSpeed;
						dy1 = -MapSpeed;
						break;
					}
					default:
					{	
						dx1 = 0;
						dy1 = 0;
						break;
					}
				}
			}
		}

		x1 += dx1;
		y1 += dy1;

		for (int i = 0; i < HeightMap; i++) // отображение карты
		{
			for (int j = 0; j < HeightMap; j++)
			{
				if (TileMap[i][j] == '0') SpriteMap.setTextureRect(IntRect(0, 25, SizeImgMap, SizeImgMap));
				if (TileMap[i][j] == '1') SpriteMap.setTextureRect(IntRect(75, 50, SizeImgMap, SizeImgMap));
				if (TileMap[i][j] == '2') SpriteMap.setTextureRect(IntRect(175, 25, SizeImgMap, SizeImgMap));
				if (TileMap[i][j] == '3') SpriteMap.setTextureRect(IntRect(175, 225, SizeImgMap, SizeImgMap));
				if (TileMap[i][j] == 'g')//Добавление орка в лист если он заспаунился
				{
					TileMap[i][j] = '0';//обнуление ячейки в которой появился орк, чтобы там больше орков не появлялось
					SpriteMap.setTextureRect(IntRect(0, 25, SizeImgMap, SizeImgMap));
					enemy.push_back(new Grant(x, y));
				}
				if (TileMap[i][j] == 't')//Добавление орка в лист если он заспаунился
				{
					TileMap[i][j] = '0';//обнуление ячейки в которой появилась башня, чтобы там больше башни не появлялись
					SpriteMap.setTextureRect(IntRect(0, 25, SizeImgMap, SizeImgMap));
					enemy.push_back(new TowerArch(x, y));
				}
				if (TileMap[i][j] == 'h')
				{
					TileMap[i][j] = '0';//обнуление ячейки в которой появился бонус, чтобы там больше бонусы не появлялись
					SpriteMap.setTextureRect(IntRect(0, 25, SizeImgMap, SizeImgMap));
					enemy.push_back(new HealthBonus(x, y));
				}
				if (TileMap[i][j] == 'd')
				{
					TileMap[i][j] = '0';//обнуление ячейки в которой появился бонус, чтобы там больше бонусы не появлялись
					SpriteMap.setTextureRect(IntRect(0, 25, SizeImgMap, SizeImgMap));
					enemy.push_back(new DamageBonus(x, y));
				}

				if (TileMap[i][j] == 'm')//Добавление орка в лист если он заспаунился
				{
					TileMap[i][j] = '3';// добавление одного объекта магмы на клетку в которой он появился
					enemy.push_back(new Magma(x, y));
				}

				SpriteMap.setPosition((int)(x + x1), (int)(y + y1));
				window.draw(SpriteMap);
				x += 25;
			}
			x = -50;
			y += 25;
		}	

		// проверка: сдвинулась ли карта на ячейку по какой либо координате
		if (((int) x1) == SizeImgMap)
		{
			UpdateMap(1);
			x1 = 0;
		}
		if (((int) x1) == -SizeImgMap)
		{
			UpdateMap(2);
			x1 = 0;
		}
		if (((int) y1) == -SizeImgMap)
		{
			UpdateMap(3);
			y1 = 0;
		}
		if (((int) y1) == SizeImgMap)
		{
			UpdateMap(4);
			y1 = 0;
		}

		if (n > 0)//проверка атаки по врагу
		{
			n += 0.01*time;
			if ((int)n == 4 ) 
			{
				for (ItEnemy = enemy.begin();ItEnemy != enemy.end(); ItEnemy++) 
				{
					if ((hero.RadiusDamage((*ItEnemy)->GetPosX(), (*ItEnemy)->GetPosY()) == true) && ((*ItEnemy)->GetLife()))
					{
						if (hero.TimeOfAction())
						{
							(*ItEnemy)->SetHp(2 * hero.GetDamage());
						}
						else (*ItEnemy)->SetHp(hero.GetDamage());
						hero.SetScore(20);
					}
				}
			}
		}

		//выстрел башни
		if (hero.GetLife())
		{
			for (ItEnemy = enemy.begin();ItEnemy != enemy.end(); ItEnemy++) 
			{
				if ((*ItEnemy)->GetType() == tow)
				{
					if (((*ItEnemy)->GetLife()) && (*ItEnemy)->ShootDelay())
					{
						arrow.push_back(new Arrow((*ItEnemy)->GetPosX(), (*ItEnemy)->GetPosY()));
					}
				}
			}
		}

		//изменение позиции стрел, если герой сдвинулся
		for (ItArrow = arrow.begin();ItArrow != arrow.end();ItArrow++)
		{
			(*ItArrow)->ChangePos(dx1,dy1);
		}

		//изменение координат врагов относительно центра, если герой движется
		for (ItEnemy = enemy.begin();ItEnemy != enemy.end(); ItEnemy++) 
		{
			(*ItEnemy)->ChangePos(dx1,dy1);
		}

		//оживление стрел
		for (ItArrow = arrow.begin();ItArrow != arrow.end();ItArrow++)
		{
			(*ItArrow)->update(time,0);
		}

		//обработка попадания стрел в игрока
		for (ItArrow = arrow.begin();ItArrow != arrow.end();ItArrow++)
		{
			if (hero.GetRect().intersects((*ItArrow)->GetRect()))
				{
					hero.SetHp((*ItArrow)->GetDamage());
					(*ItArrow)->SetLife(false);
				}
		}

		//собирание бонусов и попадане в лаву
		for (ItEnemy = enemy.begin();ItEnemy != enemy.end(); ItEnemy++)
		{
			if ((hero.GetRect().intersects((*ItEnemy)->GetRect())) && ((*ItEnemy)->GetType() == BonusHp))
			{
				hero.SetHp((*ItEnemy)->GetDamage());
				(*ItEnemy)->SetLife(false);
			}
			if ((hero.GetRect().intersects((*ItEnemy)->GetRect())) && ((*ItEnemy)->GetType() == BonusDam))
			{
				hero.StartTime2();
				(*ItEnemy)->SetLife(false);
			}
			if ((hero.GetRect().intersects((*ItEnemy)->GetRect())) && ((*ItEnemy)->GetType() == magma))
			{
				hero.SetHp((*ItEnemy)->GetDamage());
			}
		}

		//оживление врагов
		for (ItEnemy = enemy.begin();ItEnemy != enemy.end(); ItEnemy++)
		{
			if (((*ItEnemy)->GetState() == attack) && ((*ItEnemy)->GetLife()) && (*ItEnemy)->ShootDelay() && (hero.GetLife())) // начало атаки
			{
				(*ItEnemy)->SetN(time);
			}

			if ((*ItEnemy)->GetN() > 0)// если атака начата
			{
				if (((int)((*ItEnemy)->GetN()) == 4 ) && ((*ItEnemy)->RadiusDamage(0,0))) hero.SetHp((*ItEnemy)->GetDamage());
				(*ItEnemy)->SetN(time);
			}
			(*ItEnemy)->update(time, (*ItEnemy)->GetN());
		}

		//удаление врагов, если они вышли за пределы карты, и при этом мертвы, а также удаление бонусов если они подобраны
		for (ItEnemy = enemy.begin();ItEnemy != enemy.end();) 
		{
			if ((((*ItEnemy)->GetPosX() < -50) || ((*ItEnemy)->GetPosY() < -50) || ((*ItEnemy)->GetPosX() > 850) || ((*ItEnemy)->GetPosY() > 850)) && ((*ItEnemy)->GetLife() == false))
			{
				ItEnemy = enemy.erase(ItEnemy); 
			}
			else if ((((*ItEnemy)->GetType() == BonusHp) || ((*ItEnemy)->GetType() == BonusDam)) && ((*ItEnemy)->GetLife() == false))
			{
				ItEnemy = enemy.erase(ItEnemy); 
			}
			else ItEnemy++;
		}

		//удаление стрел, если они попали в героя или улетели за пределы карты
		for (ItArrow = arrow.begin();ItArrow != arrow.end();)
		{
			if (((*ItArrow)->GetPosX() < -50) || ((*ItArrow)->GetPosY() < -50) || ((*ItArrow)->GetPosX() > 850) || ((*ItArrow)->GetPosY() > 850) || ((*ItArrow)->GetLife() == false))
			{
				ItArrow = arrow.erase(ItArrow);
			}
			else ItArrow++;
		}

		//вывод на экран врагов
		for (ItEnemy = enemy.begin();ItEnemy != enemy.end(); ItEnemy++)
		{
			window.draw((*ItEnemy)->GetImage());
		}

		//вывод на экран пуль 
		for (ItArrow = arrow.begin();ItArrow != arrow.end();ItArrow++)
		{
			window.draw((*ItArrow)->GetImage());
		}

		hero.SetStay();
		//оживление героя
		hero.update(time, n);
		window.draw(hero.GetImage());
		if (n > 4) n = 0;

		//вывод очков и жизней на экран
		std::ostringstream playerHPString;
		std::ostringstream playerScoreString;
		playerHPString << hero.GetHp();
		playerScoreString << hero.GetScore();
		TextHp.setString("Здоровье: " + playerHPString.str());
		TextHp.setPosition(500, 0);
		TextScore.setString("Очки: " + playerScoreString.str());
		TextScore.setPosition(10, 0);
		if (hero.GetLife() == false)
		{
			
			TextLose.setString("ПОТРАЧЕНО");
			TextLose.setPosition(100, 350);
			window.draw(TextLose);
			TextLose1.setString("ПОТРАЧЕНО");
			TextLose1.setPosition(99, 349);
			window.draw(TextLose1);
		}
		window.draw(TextHp);
		window.draw(TextScore);

		window.display(); //Показываем объект на экране
		window.clear(); //Очищаем экран
		
	}

	for (ItEnemy = enemy.begin(); ItEnemy != enemy.end();)
	{
		ItEnemy = enemy.erase(ItEnemy);
	}

	for (ItArrow = arrow.begin(); ItArrow != arrow.end();)
	{
		ItArrow = arrow.erase(ItArrow);
	}
	return 0;
}
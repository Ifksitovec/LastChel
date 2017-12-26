#include <SFML/Graphics.hpp>
#include <iostream>
#include "Hero.h"
#include "globals.h"
#include "map_creator.h"
#include "grant.h"
#include <list>
#include <sstream>

using namespace sf;
using namespace std; 

extern char TileMap[HEIGHT_MAP][HEIGHT_MAP];

int main()
{
	Hero hero;
	Clock clock;
	Clock clock2;
	Clock gameTimeClock;//переменная игрового времени, будем здесь хранить время игры 
	int gameTime = 0;//объявили игровое время, инициализировали.

	Font font;
	font.loadFromFile("zealot.ttf");
	Text text_hp("", font, 20);
	text_hp.setColor(Color::Green);
	Text text_score("", font, 20);
	text_score.setColor(Color::Green);

	std::list<Entity*> enemy;
	std::list<Entity*>::iterator it_enemy;

	Image map_image;
	map_image.loadFromFile("images/map.png");
	Texture map;
	map.loadFromImage(map_image);//заряжаем текстуру картинкой
	Sprite s_map;//создаём спрайт для карты
	s_map.setTexture(map);//заливаем текстуру спрайтом

	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	sf::RenderWindow window(sf::VideoMode(size, size, desktop.bitsPerPixel), "The Last Knight");

	randomMapGenerate();

	while (window.isOpen())  //Пока окно открыто
	{
		static float n = 0;
		int x = -50, y = -50;
		float dx1 = 0, dy1 = 0;
		float map_speed = 10*hero.getspeed();
		static float x1 = 0, y1 = 0;
		Gstate status = hero.getState();

		float time = clock.getElapsedTime().asMicroseconds();
		float attack_time = clock2.getElapsedTime().asMilliseconds();
		if (hero.getLife()) gameTime = gameTimeClock.getElapsedTime().asSeconds();
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
			if ((hero.getState() == attack) && (hero.getLife()) && (attack_time >= delay / 3))
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
						dy1 = map_speed;
						break;
					}
					case west:
					{	
						dx1 = map_speed;
						dy1 = 0;
						break;
					}
					case east:
					{	
						dx1 = -map_speed;
						dy1 = 0;
						break;
					}
					case south:
					{	
						dx1 = 0;
						dy1 = -map_speed;
						break;
					}
					case north_west:
					{	
						dx1 = map_speed;
						dy1 = map_speed;
						break;
					}
					case north_east:
					{	
						dx1 = -map_speed;
						dy1 = map_speed;
						break;
					}
					case south_west:
					{	
						dx1 = map_speed;
						dy1 = -map_speed;
						break;
					}
					case south_east:
					{	
						dx1 = -map_speed;
						dy1 = -map_speed;
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

		//изиенение координат противника, если герой движется
		hero.setstay();

		for (int i = 0; i < HEIGHT_MAP; i++) // отображение карты
		{
			for (int j = 0; j < HEIGHT_MAP; j++)
			{
				if (TileMap[i][j] == '0') s_map.setTextureRect(IntRect(0, 25, size_img_map, size_img_map));
				if (TileMap[i][j] == '1') s_map.setTextureRect(IntRect(75, 50, size_img_map, size_img_map));
				if (TileMap[i][j] == '2') s_map.setTextureRect(IntRect(175, 25, size_img_map, size_img_map));
				if (TileMap[i][j] == '3') s_map.setTextureRect(IntRect(175, 225, size_img_map, size_img_map));
				if (TileMap[i][j] == 'g')//Добавление орка в лист если он заспаунился
				{
					TileMap[i][j] = '0';//обнуление ячейки в которой появился орк, чтобы там больше орков не появлялось
					s_map.setTextureRect(IntRect(0, 25, size_img_map, size_img_map));
					enemy.push_back(new Grant(x, y));
				}

				s_map.setPosition((int)(x + x1), (int)(y + y1));
				window.draw(s_map);
				x += 25;
			}
			x = -50;
			y += 25;
		}	

		// проверка: сдвинулась ли карта на ячейку по какой либо координате
		if (((int) x1) == size_img_map)
		{
			update_map(1);
			x1 = 0;
		}
		if (((int) x1) == -size_img_map)
		{
			update_map(2);
			x1 = 0;
		}
		if (((int) y1) == -size_img_map)
		{
			update_map(3);
			y1 = 0;
		}
		if (((int) y1) == size_img_map)
		{
			update_map(4);
			y1 = 0;
		}

		if (n > 0)//проверка атаки по врагу
		{
			n += 0.01*time;
			if ((int)n == 4 ) 
			{
				for (it_enemy = enemy.begin();it_enemy != enemy.end(); it_enemy++) 
				{
					if (hero.radiusDamage((*it_enemy)->getposX(), (*it_enemy)->getposY()) == true)
					{
						(*it_enemy)->setHP(hero.getDamage());
						hero.setScore(20);
					}
				}
			}
		}

		//оживление героя
		hero.update(time, n);
		window.draw(hero.getimage());
		if (n > 4) n = 0;

		//изменение координат врагов относительно центра, если герой движется
		for (it_enemy = enemy.begin();it_enemy != enemy.end(); it_enemy++) 
		{
			(*it_enemy)->changePos(dx1,dy1);
		}

		//оживление врагов
		for (it_enemy = enemy.begin();it_enemy != enemy.end(); it_enemy++)
		{
			if (((*it_enemy)->getState() == attack) && ((*it_enemy)->getLife()) && (*it_enemy)->shoot_delay()) // начало атаки
			{
				(*it_enemy)->setN(time);
			}

			if ((*it_enemy)->getN() > 0)// если атака начата
			{
				if (((int)((*it_enemy)->getN()) == 4 ) && ((*it_enemy)->radiusDamage(0,0))) hero.setHP((*it_enemy)->getDamage());
				(*it_enemy)->setN(time);
			}

			(*it_enemy)->update(time, (*it_enemy)->getN());
			window.draw((*it_enemy)->getimage());
		}

		//удаление врагов, если они вышли за пределы карты
		for (it_enemy = enemy.begin();it_enemy != enemy.end();) 
		{
			if ((((*it_enemy)->getposX() < -50) || ((*it_enemy)->getposY() < -50) || ((*it_enemy)->getposX() > 850) || ((*it_enemy)->getposY() > 850)) && ((*it_enemy)->getLife() == false))
				{
					it_enemy = enemy.erase(it_enemy); 
				}
			else  it_enemy++;
		}

		//вывод очков и жизней на экран
		std::ostringstream playerHPString;
		std::ostringstream playerScoreString;
		playerHPString << hero.getHP();
		playerScoreString << hero.getScore();
		text_hp.setString("Health: " + playerHPString.str());
		text_hp.setPosition(600, 0);
		text_score.setString("Score: " + playerScoreString.str());
		text_score.setPosition(10, 0);
		window.draw(text_hp);
		window.draw(text_score);


		window.display(); //Показываем объект на экране
		window.clear(); //Очищаем экран
		
	}
	return 0;
}
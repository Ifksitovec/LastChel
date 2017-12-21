#include <SFML/Graphics.hpp>
#include <iostream>
#include "Hero.h"
#include "globals.h"
#include "map_creator.h"

using namespace sf;
using namespace std; 

extern char TileMap[HEIGHT_MAP][HEIGHT_MAP];

int main()
{
	Hero hero;
	Clock clock;
	Clock gameTimeClock;//переменная игрового времени, будем здесь хранить время игры 
	int gameTime = 0;//объявили игровое время, инициализировали.

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
		int x = -50, y = -50;
		float dx1 = 0, dy1 = 0;
		float map_speed = 10*hero.getspeed();
		static float x1 = 0, y1 = 0;

		float time = clock.getElapsedTime().asMicroseconds();
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

		// установление изменения карты в зависимости от движения
		switch (hero.getState())
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

		x1 += dx1;
		y1 += dy1;

		hero.setstay();

		for (int i = 0; i < HEIGHT_MAP; i++) // отображение карты
		{
			for (int j = 0; j < HEIGHT_MAP; j++)
			{
				if (TileMap[i][j] == '0') s_map.setTextureRect(IntRect(0, 25, size_img_map, size_img_map));
				if (TileMap[i][j] == '1') s_map.setTextureRect(IntRect(75, 50, size_img_map, size_img_map));
				if (TileMap[i][j] == '2') s_map.setTextureRect(IntRect(175, 25, size_img_map, size_img_map));
				if (TileMap[i][j] == '3') s_map.setTextureRect(IntRect(175, 225, size_img_map, size_img_map));

				s_map.setPosition((int)(x + x1), (int)(y + y1));
				window.draw(s_map);
				x += 25;
			}
			x = -50;
			y += 25;
		}	

		/*for (int i = 0; i < HEIGHT_MAP; i++)
			for (int j = 0; j < HEIGHT_MAP; j++)
			{
				if (j == HEIGHT_MAP) cout << TileMap[i][j] << '\n' ;
				else cout << TileMap[i][j];

			}*/
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
		if (hero.getState() == attack)
		{
			float n = 0;
			while (n < 4)
			{
				hero.update(time,n);
				window.draw(hero.getimage());
				n += 100*n*time;
				cout << n << endl;
			}
		}
		else 
		{
			hero.update(time,0);
			window.draw(hero.getimage());
		}
		window.display(); //Показываем объект на экране
		window.clear(); //Очищаем экран
		
	}
	return 0;
}
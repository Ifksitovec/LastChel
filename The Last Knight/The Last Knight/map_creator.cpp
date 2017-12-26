#include "map_creator.h"

char TileMap[HeightMap][HeightMap];

void RandomMapGenerate() //функци€ дл€ создани€ карты 
{ 
	int RandomNumber;
	for (int i = 0; i < HeightMap; i++)
		for (int j = 0; j < HeightMap; j++)
		{
			RandomNumber = rand() % 100 ;
			if ((RandomNumber >= 0) && (RandomNumber < 50))
			{
				TileMap[i][j] = '0';
			}
			if ((RandomNumber >= 50) && (RandomNumber < 75))
			{
				TileMap[i][j] = '1';
			}
			if ((RandomNumber >= 75) && (RandomNumber < 98))
			{
				TileMap[i][j] = '2';
			}
			if ((RandomNumber >= 98) && (RandomNumber < 100))
			{
				TileMap[i][j] = '3';
			}
		}
}

void UpdateMap(int n)
{
	int RandomNumber;
	char AddTileMap[HeightMap][HeightMap];

	// сдвиг вправо на 1 €чейку
	if (n == 1) 
	{
		for (int i = 0;i < HeightMap;i++)
			for (int j = 1;j < HeightMap;j++)
			{
				AddTileMap[i][j] = TileMap[i][j-1];//копирование карты со сдвигом вправо на 1 €чейку
			}
		
		for(int i = 0;i < HeightMap;i++)//добавление левой линии карты
		{
			RandomNumber = rand() % 10000 ;
			if ((RandomNumber >= 0) && (RandomNumber < 4985)) AddTileMap[i][0] = '0';
			if ((RandomNumber >= 4985) && (RandomNumber < 4990))  AddTileMap[i][0] = 't';
			if ((RandomNumber >= 4990) && (RandomNumber < 5000))  AddTileMap[i][0] = 'g';
			if ((RandomNumber >= 5000) && (RandomNumber < 7500)) AddTileMap[i][0] = '1';
			if ((RandomNumber >= 7500) && (RandomNumber < 9800)) AddTileMap[i][0] = '2';
			if ((RandomNumber >= 9800) && (RandomNumber < 10000)) AddTileMap[i][0] = '3';
		}
	}

	// сдвиг влево на 1 €чейку
	if (n == 2) 
	{
		for (int i = 0;i < HeightMap;i++)
			for (int j = 0;j < (HeightMap - 1);j++)
			{
				AddTileMap[i][j] = TileMap[i][j+1];//копирование карты со сдвигом влево на 1 €чейку
			}
		
		for(int i = 0;i < HeightMap;i++)//добавление правой линии карты
		{
			RandomNumber = rand() % 10000 ;
			if ((RandomNumber >= 0) && (RandomNumber < 4985)) AddTileMap[i][HeightMap - 1] = '0';
			if ((RandomNumber >= 4985) && (RandomNumber < 4990))  AddTileMap[i][HeightMap - 1] = 't';
			if ((RandomNumber >= 4990) && (RandomNumber < 5000))  AddTileMap[i][HeightMap - 1] = 'g';
			if ((RandomNumber >= 5000) && (RandomNumber < 7500)) AddTileMap[i][HeightMap - 1] = '1';
			if ((RandomNumber >= 7500) && (RandomNumber < 9800)) AddTileMap[i][HeightMap - 1] = '2';
			if ((RandomNumber >= 9800) && (RandomNumber < 10000)) AddTileMap[i][HeightMap - 1] = '3';
		}
	}

	// сдвиг вверх на 1 €чейку
	if (n == 3) 
	{
		for (int i = 0;i < (HeightMap - 1);i++)
			for (int j = 0;j < HeightMap;j++)
			{
				AddTileMap[i][j] = TileMap[i+1][j];//копирование карты со сдвигом вверх на 1 €чейку
			}
		
		for(int j = 0;j < HeightMap;j++)//добавление нижней линии карты
		{
			RandomNumber = rand() % 10000 ;
			if ((RandomNumber >= 0) && (RandomNumber < 4985)) AddTileMap[HeightMap - 1][j] = '0';
			if ((RandomNumber >= 4985) && (RandomNumber < 4990))  AddTileMap[HeightMap - 1][j] = 't';
			if ((RandomNumber >= 4990) && (RandomNumber < 5000))  AddTileMap[HeightMap - 1][j] = 'g';
			if ((RandomNumber >= 5000) && (RandomNumber < 7500)) AddTileMap[HeightMap - 1][j] = '1';
			if ((RandomNumber >= 7500) && (RandomNumber < 9800)) AddTileMap[HeightMap - 1][j] = '2';
			if ((RandomNumber >= 9800) && (RandomNumber < 10000)) AddTileMap[HeightMap - 1][j] = '3';
		}
	}

	// сдвиг вниз на 1 €чейку
	if (n == 4) 
	{
		for (int i = 1;i < HeightMap;i++)
			for (int j = 0;j < HeightMap;j++)
			{
				AddTileMap[i][j] = TileMap[i-1][j];//копирование карты со сдвигом вниз на 1 €чейку
			}
		
		for(int j = 0;j < HeightMap;j++)//добавление верхней линии карты
		{
			RandomNumber = rand() % 10000 ;
			if ((RandomNumber >= 0) && (RandomNumber < 4985)) AddTileMap[0][j] = '0';
			if ((RandomNumber >= 4985) && (RandomNumber < 4990))  AddTileMap[0][j] = 't';
			if ((RandomNumber >= 4990) && (RandomNumber < 5000))  AddTileMap[0][j] = 'g';
			if ((RandomNumber >= 5000) && (RandomNumber < 7500)) AddTileMap[0][j] = '1';
			if ((RandomNumber >= 7500) && (RandomNumber < 9800)) AddTileMap[0][j] = '2';
			if ((RandomNumber >= 9800) && (RandomNumber < 10000)) AddTileMap[0][j] = '3';
		}
	}

	for (int i = 0;i < HeightMap;i++)
			for (int j = 0;j < HeightMap;j++)
			{
				TileMap[i][j] = AddTileMap[i][j];
			}
}
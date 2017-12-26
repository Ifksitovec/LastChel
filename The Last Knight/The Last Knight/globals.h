#include "SFML/Graphics.hpp"
#ifndef __GLOBALS_H__ 
#define __GLOBALS_H__ 

enum Gstate { west, NorthWest, north , NorthEast, east, SouthEast, south, SouthWest, stay, attack, block};
enum Gtype { pers, arrow, shell, tow };
const int size = 800;
const int SizeImg = 50;
const int SizeImgArr = 25;
const int SizeImgTown = SizeImg + 20;
const int HeightMap = 36;
const int SizeImgMap = 25;
extern char TileMap[HeightMap][HeightMap];
const int delay = 2400;
 
#endif
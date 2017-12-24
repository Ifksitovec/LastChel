#include "SFML/Graphics.hpp"
#ifndef __GLOBALS_H__ 
#define __GLOBALS_H__ 

enum Gstate { west, north_west, north , north_east, east, south_east, south, south_west, stay, attack, block};
const int size = 800;
const int size_img = 50;
const int HEIGHT_MAP = 36;
const int size_img_map = 25;
extern char TileMap[HEIGHT_MAP][HEIGHT_MAP];
const int delay = 2400;
 
#endif
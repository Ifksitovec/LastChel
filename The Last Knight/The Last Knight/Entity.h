#include "SFML/Graphics.hpp"
#include "globals.h"
using namespace sf;

#ifndef __CLASSESS_H__ 
#define __CLASSESS_H__ 

class Entity
{
protected:
	Gstate prevstate;
	int hp, score, shoot_time;
	float CurrentFrame;
	Clock time;
	bool life;
	float speed, dx, dy, posX, posY;
	Gstate state;
	enum { pers, shell } type;
	std::string name;
	Texture texture;
	Image image;
	Sprite sprite;

public:
	void setstay();
	float getspeed();
	Gstate getState();
	Sprite getimage();
	FloatRect getRect();
	virtual void update(float,float) = 0;
	int getHP();
	void setHP(int);
	float getposX();
	float getposY();
	bool getLife();
	void setLife(bool);
	void setScore(int);
	int getScore();
	bool shoot_delay();
};

#endif
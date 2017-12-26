#include "SFML/Graphics.hpp"
#include "globals.h"
using namespace sf;

#ifndef __CLASSESS_H__ 
#define __CLASSESS_H__ 

class Entity
{
protected:
	Gstate PrevState;
	int hp, score, ShootTime;
	float CurrentFrame;
	Clock time;
	bool life;
	float speed, dx, dy, PosX, PosY;
	Gstate state;
	Gtype type;
	Texture texture;
	Image image;
	Sprite sprite;
	int damage;
	float N; // счетчик атаки

public:
	Gtype GetType();
	FloatRect GetRect();
	float GetN(); // получение значения счетчика атаки
	void SetN(float); // изменение счетчика атаки
	int GetDamage();
	void ChangePos(float,float);
	void SetStay();
	float GetSpeed();
	Gstate GetState();
	Sprite GetImage();
	virtual bool RadiusDamage(float,float) = 0;
	virtual void update(float,float) = 0;
	virtual void control() = 0;
	virtual void SetHp(int) = 0;
	int GetHp();
	float GetPosX();
	float GetPosY();
	bool GetLife();
	void SetLife(bool);
	void SetScore(int);
	int GetScore();
	bool ShootDelay();
};

#endif
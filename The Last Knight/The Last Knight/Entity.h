#include "SFML/Graphics.hpp"
#include "globals.h"
using namespace sf;

#ifndef __CLASSESS_H__ 
#define __CLASSESS_H__ 

class Entity
{
protected:
	Gstate PrevState;
	int ShootTime;
	int hp, score;
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
	float N; // ������� �����
public:
	Gtype GetType();
	FloatRect GetRect();
	int GetDamage();
	void ChangePos(float,float);
	void SetStay();
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
	float GetN(); // ��������� �������� �������� �����
	void SetN(float); // ��������� �������� �����
	bool ShootDelay();
};

#endif
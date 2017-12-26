#include "Entity.h"

#ifndef __ARROW_H__ 
#define __ARROW_H__ 

class Arrow : public Entity
{
public:
	Arrow(float, float);
	void update(float,float);
	void control();
	void SetHp(int);
	bool RadiusDamage(float,float);
};

#endif
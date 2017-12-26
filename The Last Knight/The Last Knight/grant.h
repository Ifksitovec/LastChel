#include "Entity.h"

#ifndef __GRANT_H__ 
#define __GRANT_H__ 

class Grant : public Entity
{
public:
	Grant(float, float);
	void update(float,float);
	void control();
	void SetHp(int);
	bool RadiusDamage(float,float);
};

#endif
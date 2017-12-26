#include "Entity.h"

#ifndef __MAGMA_H__ 
#define __MAGMA_H__ 

class Magma : public Entity
{
public:
	Magma(float, float);
	void update(float,float);
	void control();
	void SetHp(int);
	bool RadiusDamage(float,float);
};

#endif
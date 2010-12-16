/*
 *  NonNom.h
 *  Survival
 *
 *  Created by Chris Cooper on 10-12-14.
 *  Copyright 2010 Chris Cooper. All rights reserved.
 *
 */

#include "Logistics.h"
#include "Foodbit.h"


#ifndef _NOMLET_
#define _NOMLET_

class Nomlet {
	
public:
	Nomlet();
	Nomlet(Nomlet &father, Nomlet &mother);
	void eatFoodbit(Foodbit &foodbit);
	Coordinate getLocation();
	float getDirection();
	float getSize();
	void move();
	void capLocation();
	
private:
	Coordinate location;
	float speed;
	double energy;
	float direction;
	float size;
};

#endif
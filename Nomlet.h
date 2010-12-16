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
	
private:
	Coordinate location;
	Coordinate velocity;
	double energy;
};

#endif
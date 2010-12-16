/*
 *  Foodbit.h
 *  Survival
 *
 *  Created by Chris Cooper on 10-12-14.
 *  Copyright 2010 Chris Cooper. All rights reserved.
 *
 */

#ifndef _FOODBIT_
#define _FOODBIT_

#include "Logistics.h"
#include <iostream>
#include "Nomlet.h"

class Nomlet;

class Foodbit {
	
public:
	Foodbit();
	float getSize();
	Coordinate getLocation();
	void giveFood(Nomlet &nomlet);
	void evaluateSize();
	
private:
	Coordinate location;
	double energy;
	float size;
};

#endif
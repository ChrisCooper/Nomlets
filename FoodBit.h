/*
 *  Foodbit.h
 *  Survival
 *
 *  Created by Chris Cooper on 10-12-14.
 *  Copyright 2010 Chris Cooper. All rights reserved.
 *
 */

#include "Logistics.h"
#include <iostream>

#ifndef _FOODBIT_
#define _FOODBIT_

class Foodbit {
	
public:
	Foodbit();
	float getSize();
	Coordinate getLocation();
	
private:
	Coordinate location;
	double energy;
	float size;
};

#endif
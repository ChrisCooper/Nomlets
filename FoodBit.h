/*
 *  FoodBit.h
 *  Survival
 *
 *  Created by Chris Cooper on 10-12-14.
 *  Copyright 2010 Chris Cooper. All rights reserved.
 *
 */

#include "Logistics.h"

#ifndef _FOODBIT_
#define _FOODBIT_

class FoodBit {
	
public:
	FoodBit();
	
private:
	Coordinate location;
	double energy;
};

#endif
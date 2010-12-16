/*
 *  Foodbit.cpp
 *  Survival
 *
 *  Created by Chris Cooper on 10-12-14.
 *  Copyright 2010 Chris Cooper. All rights reserved.
 *
 */

#include "Foodbit.h"
#include "Environment.h"
#include <math.h>

Foodbit::Foodbit(){
	location = randomMapLocation();
	
	energy = rand() % (MAX_FOOD_VALUE - MIN_FOOD_VALUE) + MIN_FOOD_VALUE;
	size = sqrt(energy);
}

float Foodbit::getSize(){
	return size;
}

Coordinate Foodbit::getLocation(){
	return location;
}
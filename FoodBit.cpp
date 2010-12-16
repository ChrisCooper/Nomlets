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
	location.x = (((float)rand()) / RAND_MAX) * MAP_SIZE / 2;
	if (rand() % 2 ){
		location.x = -location.x;
	}
	location.y = (((float)rand()) / RAND_MAX) * MAP_SIZE / 2;
	if (rand() % 2){
		location.y = -location.y;
	}
	
	energy = rand() % (MAX_FOOD_VALUE - MIN_FOOD_VALUE) + MIN_FOOD_VALUE;
	size = sqrt(energy);
}

float Foodbit::getSize(){
	return size;
}

Coordinate Foodbit::getLocation(){
	return location;
}
/*
 *  Logistics.cpp
 *  Survival
 *
 *  Created by Chris Cooper on 10-12-14.
 *  Copyright 2010 Chris Cooper. All rights reserved.
 *
 */

#include "Logistics.h"
#include "Environment.h"
#include "Utilities.h"

Coordinate randomMapLocation(){
	Coordinate location;
	location.x = zeroToOneUniform() * (MAP_SIZE * 0.975) / 2;
	if (rand() % 2 ){
		location.x = -location.x;
	}
	location.y = zeroToOneUniform() * (MAP_SIZE * 0.975) / 2;
	if (rand() % 2){
		location.y = -location.y;
	}
	return location;
}
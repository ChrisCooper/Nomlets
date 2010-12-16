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
	evaluateSize();
}

void Foodbit::evaluateSize(){
	size = sqrt(energy);
}

void Foodbit::giveFood(Nomlet &nomlet){
	float energyGiven = (rand() % (MAX_FOOD_VALUE - MIN_FOOD_VALUE) + MIN_FOOD_VALUE) / AVG_FOOD_BITES;
	energyGiven = max(energyGiven, 0.0f);
	energy -= energyGiven;
	nomlet.giveEnergy(energyGiven);
	evaluateSize();
}

float Foodbit::getSize(){
	return size;
}

Coordinate Foodbit::getLocation(){
	return location;
}
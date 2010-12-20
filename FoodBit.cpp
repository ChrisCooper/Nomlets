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
	energyGiven = min((float)energy, energyGiven);
	if (energyGiven < 0){
		energyGiven = 0;
	}
	energy -= energyGiven;
	nomlet.giveEnergy(energyGiven);
	evaluateSize();
}

double Foodbit::getEnergy(){
	return energy;
}

float Foodbit::getSize(){
	return size + FOODBIT_MINIMUM_SIZE;
}

Coordinate Foodbit::getLocation(){
	return location;
}
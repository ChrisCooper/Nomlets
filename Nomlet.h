/*
 *  Nonlet.h
 *  Survival
 *
 *  Created by Chris Cooper on 10-12-14.
 *  Copyright 2010 Chris Cooper. All rights reserved.
 *
 */


#ifndef _NOMLET_
#define _NOMLET_


#include "Logistics.h"
#include "Foodbit.h"

class Foodbit;

class Nomlet {
	
public:
	Nomlet();
	Nomlet(Nomlet &father, Nomlet &mother);
	void eatFoodbit(Foodbit &foodbit);
	Coordinate getLocation();
	float getDirection();
	float getSize();
	double getEnergy();
	void move();
	void capLocation();
	void accelerate();
	void turn(float amount);
	void giveEnergy(double energyGiven);
	float getHealthiness();
	void clampEnergy();
	
private:
	Coordinate location;
	float speed;
	double energy;
	float direction;
	float size;
};

#endif
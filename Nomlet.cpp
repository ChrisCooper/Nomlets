/*
 *  Nonlet.cpp
 *  Survival
 *
 *  Created by Chris Cooper on 10-12-14.
 *  Copyright 2010 Chris Cooper. All rights reserved.
 *
 */

#include "Nomlet.h"
#include "Environment.h"
#include "Utilities.h"
#include <math.h>

Nomlet::Nomlet(){
	location = randomMapLocation();
	
	speed = NOMLET_TOP_SPEED;
	
	energy = NOMLET_STARTING_ENERGY;
	size = sqrt(energy);
	
	direction = rand() % 360;
	
}

Nomlet::Nomlet(Nomlet &father, Nomlet &mother){
}

void Nomlet::eatFoodbit(Foodbit &foodbit){
}

void Nomlet::accelerate(){
	speed += NOMLET_ACCELLERATION;
	speed = min(speed, NOMLET_TOP_SPEED);
}

void Nomlet::turn(float amount){
	direction += amount;
	if (direction > 360){
		direction -= 360;
	}
	if (direction < 0){
		direction += 360;
	}
}

void Nomlet::move(){
	location.x += speed * cos(degreeToRadian(-direction));
	location.y += speed * sin(degreeToRadian(-direction));
	
	capLocation();
	
	speed *= NOMLET_INERTIA;
}

void Nomlet::eatIfPossible(Foodbit &theFoodbit){
	
}

void Nomlet::giveEnergy(double energyGiven){
	energy += energyGiven;
}

void Nomlet::capLocation(){
	location.x = min(location.x, MAP_SIZE / 2);
	location.x = max(location.x, -(MAP_SIZE / 2));
	location.y = min(location.y, MAP_SIZE / 2);
	location.y = max(location.y, -(MAP_SIZE / 2));
}

Coordinate Nomlet::getLocation(){
	return location;
}

float Nomlet::getDirection(){
	return direction;
}

float Nomlet::getSize(){
	return size;
}

double Nomlet::getEnergy(){
	return energy;
}

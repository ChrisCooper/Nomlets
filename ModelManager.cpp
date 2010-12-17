/*
 *  ModelManager.cpp
 *  Survival
 *
 *  Created by Chris Cooper on 10-12-14.
 *  Copyright 2010 Chris Cooper. All rights reserved.
 *
 */

#include "ModelManager.h"
#include "Environment.h"

ModelManager::ModelManager(){
	for (int i = 0; i < INITIAL_FOODBITS; i++){
		Foodbit *foodbit = new Foodbit();
		foodbits.push_back(*foodbit);
	}
	
	for (int i = 0; i < INITIAL_NOMLETS; i++){
		Nomlet *nomlet = new Nomlet();
		nomlets.push_back(*nomlet);
	}
}

vector<Foodbit> &ModelManager::getFoodbits(){
	return foodbits;
}

vector<Nomlet> &ModelManager::getNomlets(){
	return nomlets;
}

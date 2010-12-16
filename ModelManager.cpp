/*
 *  ModelManager.cpp
 *  Survival
 *
 *  Created by Chris Cooper on 10-12-14.
 *  Copyright 2010 Chris Cooper. All rights reserved.
 *
 */

#include "ModelManager.h"

ModelManager::ModelManager(){
	for (int i = 0; i < 200; i++){
		Foodbit *foodbit = new Foodbit();
		foodbits.push_back(*foodbit);
	}
	
	for (int i = 0; i < 10; i++){
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

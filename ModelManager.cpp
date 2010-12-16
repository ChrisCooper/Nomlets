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
	for (int i = 0; i < 100; i++){
		Foodbit *foodbit = new Foodbit();
		foodbits.push_back(*foodbit);
	}
}

vector<Foodbit> &ModelManager::getFoodbits(){
	return foodbits;
}

vector<Nomlet> &ModelManager::getNomlets(){
	return nomlets;
}

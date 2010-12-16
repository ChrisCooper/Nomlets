/*
 *  ModelManager.h
 *  Survival
 *
 *  Created by Chris Cooper on 10-12-14.
 *  Copyright 2010 Chris Cooper. All rights reserved.
 *
 */

#ifndef _MODEL_MANAGER_
#define _MODEL_MANAGER_

#include <iostream>
#include <vector>
#include "Nomlet.h"
#include "Foodbit.h"

using namespace std;

class ModelManager {
	
public:
	ModelManager();
	vector<Foodbit> &getFoodbits();
	vector<Nomlet> &getNomlets();
	
private:
	vector<Foodbit> foodbits;
	vector<Nomlet> nomlets;
};

#endif
/*
 *  EngineCore.cpp
 *  Nomlets
 *
 *  Created by Chris Cooper on 10-12-15.
 *  Copyright 2010 Chris Cooper. All rights reserved.
 *
 */

#include "EngineCore.h"
#include "Environment.h"
#include "CameraController.h"
#include "InputCore.h"

void update(int value) {
	checkInput();
	
	updateCamera();
	
	moveNomlets();
	
	evaluateCollisions();
	
	glutPostRedisplay();
	
	glutTimerFunc(25, update, 0);
}


void moveNomlets(){
	vector<Nomlet> &nomlets = manager->getNomlets();
	
	for (int i = 0; i < nomlets.size(); i++) {
		Nomlet &nomlet = nomlets[i];
		
		nomlet.move();
	}
}

void evaluateCollisions(){
	vector<Foodbit> &foodbits = manager->getFoodbits();
	vector<Nomlet> &nomlets = manager->getNomlets();
	Nomlet &nomlet = nomlets[0];
	for (int i = 0; i < foodbits.size(); i++) {
		Foodbit &foodbit = foodbits[i];
		
		//Big approximations here...
		float xD = (foodbit.getLocation().x - nomlet.getLocation().x)*(foodbit.getLocation().x - nomlet.getLocation().x);
		float yD = (foodbit.getLocation().y - nomlet.getLocation().y)*(foodbit.getLocation().y - nomlet.getLocation().y);
		float distance = xD+yD;
		if (distance < NOMLET_EATING_RANGE){
			foodbit.giveFood(nomlet);
		}
	}
}
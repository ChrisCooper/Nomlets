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
	
	
	//cullObjects();
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
	
	//This can be improved from O(N*F).
	//Look into using a quadtree.
	for (int i = 0; i < nomlets.size(); i++){
		Nomlet &nomlet = nomlets[i];
		for (int j = 0; j < foodbits.size(); j++) {
			Foodbit &foodbit = foodbits[j];
			
			//Big approximations here...
			float xD = (foodbit.getLocation().x - nomlet.getLocation().x)*(foodbit.getLocation().x - nomlet.getLocation().x);
			float yD = (foodbit.getLocation().y - nomlet.getLocation().y)*(foodbit.getLocation().y - nomlet.getLocation().y);
			float distance = xD+yD;
			if (distance < NOMLET_EATING_RANGE){
				foodbit.giveFood(nomlet);
			}
		}
	}
}
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
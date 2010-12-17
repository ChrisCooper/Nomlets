/*
 *  InputCore.cpp
 *  Nomlets
 *
 *  Created by Chris Cooper on 10-12-15.
 *  Copyright 2010 Chris Cooper. All rights reserved.
 *
 */

#include "InputCore.h"
#include "CameraController.h"
#include "Environment.h" 

void checkInput(){
	if(keyDown[27]){
		exit(0);
	}
	if (specialKeyDown[GLUT_KEY_LEFT]){
		rotateCamera(LEFT);
	}
	if (specialKeyDown[GLUT_KEY_RIGHT]){
		rotateCamera(RIGHT);
	}
	if (specialKeyDown[GLUT_KEY_UP]){
		zoomCamera(IN);
	}
	if (specialKeyDown[GLUT_KEY_DOWN]){
		zoomCamera(OUT);
	}
	
	//Nomlet control
	vector<Nomlet> &nomlets = manager->getNomlets();
	
	if (nomlets.size() > 0){
		Nomlet &nomlet = nomlets[0];
		if(keyDown['w']){
			nomlet.accelerate();
		}
		if(keyDown['a']){
			nomlet.turn(NOMLET_TURN_SPEED);
		}
		if(keyDown['d']){
			nomlet.turn(-NOMLET_TURN_SPEED);
		}
		if(keyDown['1']){
			nomlet.giveEnergy(500);
		}
	}

}

//Called when a key is pressed
void handleKeypress(unsigned char key, int x, int y) {
	keyDown[key] = true;
}

void handleKeyUp(unsigned char key, int x, int y){
	keyDown[key] = false;
}

void handleSpecialKey(int key, int x, int y){
	specialKeyDown[key] = true;
}

void handleSpecialKeyUp(int key, int x, int y){
	specialKeyDown[key] = false;
}

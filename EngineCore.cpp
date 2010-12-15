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

//Called every 25(?) milliseconds
void update(int value) {
    cameraAngle -= 0.2f;
    if (cameraAngle > 360) {
        cameraAngle -= 360;
    }
	if (cameraAngle < 0) {
        cameraAngle += 360;
    }
	
	glutPostRedisplay();
	
	glutTimerFunc(25, update, 0);
}
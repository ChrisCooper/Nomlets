/*
 *  CameraController.cpp
 *  Nomlets
 *
 *  Created by Chris Cooper on 10-12-15.
 *  Copyright 2010 Chris Cooper. All rights reserved.
 *
 */

#include "CameraController.h"
#include "Environment.h"

void updateCamera(){
	cameraAngle += cameraAngleSpeed;
	
	if (cameraAngle > 360) {
		cameraAngle -= 360;
	}
	if (cameraAngle < 0) {
		cameraAngle += 360;
	}
	
	if (cameraAngleSpeed > cameraIdleSpinSpeed || cameraAngleSpeed < -cameraIdleSpinSpeed){
		cameraAngleSpeed *= cameraAngleInertia;
	}
	
	if (cameraDistance > maximumCameraDistance) {
		cameraDistance = maximumCameraDistance;
	}
	if (cameraDistance < minimumCameraDistance) {
		cameraDistance = minimumCameraDistance;
	}
	
	cameraDistance += cameraDistanceSpeed;
	
	cameraDistanceSpeed *= cameraDistanceInertia;
}

void rotateCamera(Direction direction){
	switch (direction) {
		case LEFT:
			cameraAngleSpeed += cameraAngleAcceleration;
			break;
		case RIGHT:
			cameraAngleSpeed -= cameraAngleAcceleration;
			break;
		default:
			break;
	}
}

void zoomCamera(Direction direction){
	switch (direction) {
		case IN:
			cameraDistanceSpeed -= cameraDistanceAcceleration;
			break;
		case OUT:
			cameraDistanceSpeed += cameraDistanceAcceleration;
			break;
		default:
			break;
	}
}
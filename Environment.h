/*
 *  Environment.h
 *  Nomlets
 *
 *  Created by Chris Cooper on 10-12-15.
 *  Copyright 2010 Chris Cooper. All rights reserved.
 *
 */

#include <iostream>
#include <stdlib.h>
#include "ModelManager.h"

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

enum Direction {
	LEFT,
	RIGHT,
	IN,
	OUT
};

//Camera
extern float cameraAngle;
extern float cameraAngleSpeed;
extern float cameraAngleInertia;
extern float cameraAngleAcceleration;
extern float cameraIdleSpinSpeed;

extern float cameraDistance;
extern float cameraDistanceSpeed;
extern float cameraDistanceInertia;
extern float cameraDistanceAcceleration;
extern float minimumCameraDistance;
extern float maximumCameraDistance;


//Game configuration
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
extern const int TIME_INTERVAL;

extern float MAP_SIZE;
extern int MAX_FOOD_VALUE;
extern int MIN_FOOD_VALUE;
extern int NOMLET_STARTING_ENERGY;


//Lighting
extern GLfloat ambientColor[];
extern GLfloat positionedLightColor[];
extern GLfloat positionedLightPosition[];
extern GLfloat directedLightColor[];
extern GLfloat directedLightPosition[];


//Input
extern bool keyDown[256];
extern bool specialKeyDown[256];


//Colors
extern GLfloat groundColor[4];
extern GLfloat foodbitColor[4];
extern GLfloat nomletColor[4];

//Object Attributes
extern float FOODBIT_SIZE;
extern float NOMLET_SIZE;
extern float NOMLET_LENGTH;

//Game Globals
extern ModelManager *manager;

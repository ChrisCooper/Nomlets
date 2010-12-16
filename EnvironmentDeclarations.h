/*
 *  EnvironmentDeclarations.h
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

//Camera
float cameraAngle = 45.0f;
float cameraAngleSpeed = 0.2f;
float cameraAngleInertia = 0.8f;
float cameraAngleAcceleration = 0.8f;
float cameraIdleSpinSpeed = 0.07f;

float cameraDistance = 10.0f;
float cameraDistanceSpeed = 0.0f;
float cameraDistanceInertia = 0.5f;
float cameraDistanceAcceleration = 0.3f;
float minimumCameraDistance = 3.0f;
float maximumCameraDistance = 30.0f;


//Game configuration
const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 800;
const int TIME_INTERVAL = 25;

float MAP_SIZE = 10.0f;
int MAX_FOOD_VALUE = 1500;
int MIN_FOOD_VALUE = 50;
int AVG_FOOD_BITES = 10;
int NOMLET_STARTING_ENERGY = MAX_FOOD_VALUE*3;
float NOMLET_TOP_SPEED = 0.03f;
float NOMLET_INERTIA = 0.8f;
float NOMLET_ACCELLERATION = 0.05f;
float NOMLET_TURN_SPEED = 5;
float NOMLET_EATING_RANGE = 0.05;

//Lighting
GLfloat ambientColor[] = {0.2f, 0.2f, 0.2f, 1.0f};
GLfloat positionedLightColor[] = {0.5f, 0.5f, 0.5f, 1.0f}; 
GLfloat positionedLightPosition[] = {4.0f, 0.0f, 8.0f, 1.0f};
GLfloat directedLightColor[] = {0.5f, 0.2f, 0.2f, 1.0f}; 
GLfloat directedLightPosition[] = {-1.0f, 0.5f, 0.5f, 0.0f};


//Input
bool keyDown[256];
bool specialKeyDown[256];


//Colors
GLfloat groundColor[4] = {0.1f, 0.4f, 0.1f, 1.0f};
GLfloat foodbitColor[4] = {0.7f, 0.7f, 0.0f, 1.0f};
GLfloat nomletColor[4] = {0.3f, 0.3f, 1.0f, 1.0f};

//Object Attributes
float FOODBIT_SIZE = 0.002f;
float NOMLET_SIZE = 0.1f;
float NOMLET_LENGTH = 0.2f;


//Game Globals
ModelManager *manager = NULL;


//Costs
float MOVEMENT_COST = 20.0f;

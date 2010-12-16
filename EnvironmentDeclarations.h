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
GLfloat groundColor[4] = {0.3f, 0.9f, 0.3f, 1.0f};

//Object Attributes
float FOODBIT_SIZE = 0.003;


//Game Globals
ModelManager *manager = NULL;

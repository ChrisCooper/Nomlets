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

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

//Camera
float cameraAngle = 45.0f;
float cameraAngleSpeed = 0.2f;
float cameraAngleInertia = 0.9f;
float cameraAngleAcceleration = 0.6f;

float cameraDistance = 10.0f;
float cameraDistanceSpeed = 0.0f;
float cameraDistanceInertia = 0.5f;
float cameraDistanceAcceleration = 0.3f;
float minimumCameraDistance = 3.0f;
float maximumCameraDistance = 20.0f;


//Game configuration
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int TIME_INTERVAL = 25;

//Lighting
GLfloat ambientColor[] = {0.2f, 0.2f, 0.2f, 1.0f};
GLfloat positionedLightColor[] = {0.5f, 0.5f, 0.5f, 1.0f}; 
GLfloat positionedLightPosition[] = {4.0f, 0.0f, 8.0f, 1.0f};
GLfloat directedLightColor[] = {0.5f, 0.2f, 0.2f, 1.0f}; 
GLfloat directedLightPosition[] = {-1.0f, 0.5f, 0.5f, 0.0f};


//Input
bool keyDown[256];
bool specialKeyDown[256];

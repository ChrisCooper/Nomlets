/*
 *  Environment.h
 *  Nomlets
 *
 *  Created by Chris Cooper on 10-12-15.
 *  Copyright 2010 Chris Cooper. All rights reserved.
 *
 */

float cameraAngle = 0.0f;


//Game configuration
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

//Lighting
GLfloat ambientColor[] = {0.2f, 0.2f, 0.2f, 1.0f};
GLfloat positionedLightColor[] = {0.5f, 0.5f, 0.5f, 1.0f}; 
GLfloat positionedLightPosition[] = {4.0f, 0.0f, 8.0f, 1.0f};
GLfloat directedLightColor[] = {0.5f, 0.2f, 0.2f, 1.0f}; 
GLfloat directedLightPosition[] = {-1.0f, 0.5f, 0.5f, 0.0f};
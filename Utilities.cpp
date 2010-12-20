/*
 *  Utilities.cpp
 *  Nomlets
 *
 *  Created by Chris Cooper on 10-12-15.
 *  Copyright 2010 Chris Cooper. All rights reserved.
 *
 */

#include "Utilities.h"
#include <iostream>
#include <math.h>


#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif 

#define PI 3.14159265f

using namespace std;

float zeroToOneUniform(){
	return (((float)rand()) / ((float)RAND_MAX + 1));
}

float degreeToRadian(float degree) {
	float radian = 0;
	radian = degree * (PI/180);
	return radian;
}

void drawAxes (float size)
{
    glLineWidth (2.0);
    glColor3f (1.0f, 1.0f, 1.0f);
    glDisable   (GL_LIGHTING);
	
    glPushMatrix ();
	
	glScalef (size, size, size);
	
	glBegin (GL_LINES);
	glVertex3f (0.0f,0.0f,0.0f); glVertex3f (1.0f,0.0f,0.0f);
	glVertex3f (0.0f,0.0f,0.0f); glVertex3f (0.0f,1.0f,0.0f);
	glVertex3f (0.0f,0.0f,0.0f); glVertex3f (0.0f,0.0f,1.0f);
	glEnd ();
	
	glRasterPos3f (1.1, 0.0, 0.0);
	glutBitmapCharacter (GLUT_BITMAP_HELVETICA_18, 'x');
	
	glRasterPos3f (0.0, 1.1, 0.0);
	glutBitmapCharacter (GLUT_BITMAP_HELVETICA_18, 'y');
	
	glRasterPos3f (0.0, 0.0, 1.1);
	glutBitmapCharacter (GLUT_BITMAP_HELVETICA_18, 'z');
	
    glPopMatrix ();
	glEnable   (GL_LIGHTING);
}

float biasedFloat(float first, float second, float weightToFirst){
	//clamp weightToFirst
	weightToFirst = min(weightToFirst, 1.0f);
	weightToFirst = max(weightToFirst, 0.0f);
	return weightToFirst*first + (1.0f - weightToFirst)*second;
}

double sigmoid(double netinput, double response){
	return ( 1.0 / ( 1.0 + exp(-netinput / response)));
}



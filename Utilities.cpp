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


#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif 

#define PI 3.14159265f

float zeroToOneUniform(){
	return (((float)rand()) / RAND_MAX);
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

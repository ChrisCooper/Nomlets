/*
 *  GraphicsBasics.cpp
 *  Nomlets
 *
 *  Created by Chris Cooper on 10-12-15.
 *  Copyright 2010 Chris Cooper. All rights reserved.
 *
 */

#include "GraphicsCore.h"
#include "Environment.h"

void initRendering() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
    glEnable(GL_COLOR_MATERIAL);
}

void drawScene() {
	
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

	gluLookAt(cameraDistance, 15.0 - cameraDistance*0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	glRotatef(cameraAngle, 0.0f, 1.0f, 0.0f);
	
	addLighting(); 
	
	drawObjects();
	
	glutSolidTeapot(1.0); 
    
   glutSwapBuffers();
}

void drawObjects(){
	
	glPushMatrix();
	glTranslatef(0.0f, -1.0f, 0.0f);
	glScalef(MAP_SIZE, 0.1f, MAP_SIZE);
	glColor3fv(groundColor);
	glutSolidCube(1.0f);
	glPopMatrix();
	
	glColor3f(1.0f, 1.0f, 1.0f);
	glutSolidTeapot(1.0); 
}
	
void addLighting(){
	
	//Add ambient light
    GLfloat ambientColor[] = {0.2f, 0.2f, 0.2f, 1.0f};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);
	
    //Add positioned light
    GLfloat positionedLightColor[] = {0.5f, 0.5f, 0.5f, 1.0f}; 
    GLfloat positionedLightPosition[] = {4.0f, 0.0f, 8.0f, 1.0f};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, positionedLightColor);
    glLightfv(GL_LIGHT0, GL_POSITION, positionedLightPosition);
	
    //Add directed light
    GLfloat directedLightColor[] = {0.5f, 0.2f, 0.2f, 1.0f}; 
    //Coming from the direction (-1, 0.5, 0.5)
    GLfloat directedLightPosition[] = {-1.0f, 0.5f, 0.5f, 0.0f};
    glLightfv(GL_LIGHT1, GL_DIFFUSE, directedLightColor);
    glLightfv(GL_LIGHT1, GL_POSITION, directedLightPosition);
}

void handleResize(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)w / (float)h, 1.0, 200.0);
}

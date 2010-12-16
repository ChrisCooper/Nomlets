/*
 *  GraphicsBasics.h
 *  Nomlets
 *
 *  Created by Chris Cooper on 10-12-15.
 *  Copyright 2010 Chris Cooper. All rights reserved.
 *
 */

#ifndef _GRAPHICS_CORE_
#define _GRAPHICS_CORE_

#include <iostream>
#include <stdlib.h>


#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

using namespace std;

void initRendering();
void drawScene();
void drawObjects();
void drawNomlets();
void drawFoodbits();
void drawGround();
void addLighting();
void handleResize(int w, int h);


#endif
/*
 *  main.cpp
 *  Nomlets
 *
 *  Created by Chris Cooper on 10-12-14.
 *  Copyright 2010 Chris Cooper. All rights reserved.
 *
 */

#include <iostream>
#include "GraphicsCore.h"
#include "InputCore.h"
#include "EngineCore.h"
#include "EnvironmentDeclarations.h"

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	
    glutCreateWindow("Nomlets");
	
    initRendering();
	
    glutDisplayFunc(drawScene);
    glutKeyboardFunc(handleKeypress);
    glutReshapeFunc(handleResize);
	
    glutTimerFunc(25, update, 0);
	
    glutMainLoop();
    return 0;
}

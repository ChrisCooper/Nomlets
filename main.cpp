/*
 *  main.cpp
 *  Nomlets
 *
 *  Created by Chris Cooper on 10-12-14.
 *  Copyright 2010 Chris Cooper. All rights reserved.
 *
 *	Thanks to ai-junkie.com for the project idea, and source code assistance!
 *
 */

#include <iostream>
#include "GraphicsCore.h"
#include "InputCore.h"
#include "EngineCore.h"
#include "EnvironmentDeclarations.h"

void setHandlers();
void initializeGameState();

int main(int argc, char** argv) {
	srand(time(0));
	
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	
    glutCreateWindow("Nomlets");
	
    initRendering();
	
	setHandlers();
	
	initializeGameState();
	
    glutTimerFunc(25, update, 0);
	
    glutMainLoop();
    return 0;
}

void setHandlers(){
	glutDisplayFunc(drawScene);
    glutKeyboardFunc(handleKeypress);
	glutKeyboardUpFunc(handleKeyUp);
	glutSpecialFunc(handleSpecialKey);
	glutSpecialUpFunc(handleSpecialKeyUp);
	glutIgnoreKeyRepeat(true);
	glutReshapeFunc(handleResize);
}

void initializeGameState(){
	manager = new ModelManager();
}

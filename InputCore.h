/*
 *  InputCore.h
 *  Nomlets
 *
 *  Created by Chris Cooper on 10-12-15.
 *  Copyright 2010 Chris Cooper. All rights reserved.
 *
 */

#ifndef _INPUT_CORE_
#define _INPUT_CORE_

#import <iostream>

using namespace std;

void checkInput();

void handleKeypress(unsigned char key, int x, int y);
void handleKeyUp(unsigned char key, int x, int y);
void handleSpecialKey(int key, int x, int y);
void handleSpecialKeyUp(int key, int x, int y);

#endif
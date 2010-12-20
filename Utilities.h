/*
 *  Utilities.h
 *  Nomlets
 *
 *  Created by Chris Cooper on 10-12-15.
 *  Copyright 2010 Chris Cooper. All rights reserved.
 *
 */

float zeroToOneUniform();

float degreeToRadian(float degree);

void drawAxes (float size);

float biasedFloat(float first, float second, float weightToFirst);

double sigmoid(double netinput, double response);
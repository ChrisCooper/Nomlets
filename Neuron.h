/*
 *  Neuron.h
 *  Nomlets
 *
 *  Created by Chris Cooper on 10-12-16.
 *  Copyright 2010 Chris Cooper. All rights reserved.
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Neuron {
	
private:
	int numInputs;
	vector<double> weights;

public:
	Neuron(int _numInputs);
	int getNumInputs();
	vector<double> &getWeights();
	void setWeights(vector<double> newWeights);
};
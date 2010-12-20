/*
 *  Neuron.cpp
 *  Nomlets
 *
 *  Created by Chris Cooper on 10-12-16.
 *  Copyright 2010 Chris Cooper. All rights reserved.
 *
 */

#include "Neuron.h"
#include "Utilities.h"

Neuron::Neuron(int _numInputs) {
	
	numInputs = _numInputs + 1; //Add 1 for the threshold
	
	weights.reserve(numInputs);
	
	for (int i=0; i<numInputs; ++i) {
		weights.push_back(zeroToOneUniform());
	}	
}

int Neuron::getNumInputs(){
	return numInputs;
}

vector<double> &Neuron::getWeights(){
	return weights;
}

void Neuron::setWeights(vector<double> newWeights){
	weights.clear();
	weights.reserve(newWeights.size());
	
	//Copy entries over
	weights.insert(newWeights.end(), newWeights.begin(), newWeights.end());
}
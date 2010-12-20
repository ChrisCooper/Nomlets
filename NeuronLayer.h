/*
 *  NeuronLayer.h
 *  Nomlets
 *
 *  Created by Chris Cooper on 10-12-18.
 *  Copyright 2010 Chris Cooper. All rights reserved.
 *
 */

#include <iostream>
#include <vector>
#include "Neuron.h"

using namespace std;

class NeuronLayer {
	
private:
	int numNeurons;
	vector<Neuron> neurons;
	
public:	
	NeuronLayer(int _numNeurons, int inputsPerNeuron);
	vector<Neuron> &getNeurons();
	int getNumNeurons();
};
/*
 *  NeuralNetwork.h
 *  Nomlets
 *
 *  Created by Chris Cooper on 10-12-18.
 *  Copyright 2010 Chris Cooper. All rights reserved.
 *
 */

#ifndef _NEURALNETWORK_
#define _NEURALNETWORK_

#include <iostream>
#include <vector>
#include "NeuronLayer.h"
#include "Environment.h"

class NeuralNetwork {
	
private:
	int numInputs;
	int numOutputs;
	int numHiddenLayers;
	int neuronsPerHiddenLayer;
	
	vector<NeuronLayer> layers; // Includes output layer
	
	vector<double> weights;
	bool weightsNeedsUpdate;
	
public:
	NeuralNetwork();
	NeuralNetwork(int _numInputs, int _numOutputs, int _numHiddenLayers, int _neuronsPerHiddenLayer);
	
	void fillNetwork();
	
	vector<double> &getWeights();
	int getNumWeights();
	void setWeights(vector<double> &weights);
	
	vector<double> update(vector<double> &inputs);
	
	void describeNetwork();
	void showUpdateResults(vector<double> inputs);
};

#endif
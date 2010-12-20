/*
 *  NeuralNetwork.h
 *  Nomlets
 *
 *  Created by Chris Cooper on 10-12-18.
 *  Copyright 2010 Chris Cooper. All rights reserved.
 *
 */

#include <iostream>
#include <vector>
#include "NeuronLayer.h"

class NeuralNet {
	
private:
	int numInputs;
	int numOutputs;
	int numHiddenLayers;
	int neuronsPerHiddenLayer;
	
	vector<NeuronLayer> layers; // Includes output layer
	
	vector<double> weights;
	bool weightsNeedsUpdate;
	
public:
	NeuralNet(int _numInputs, int _numOutputs, int _numHiddenLayers, int _neuronsPerHiddenLayer);
	
	void fillNetwork();
	
	vector<double> &getWeights();
	int getNumWeights();
	void setWeights(vector<double> &weights);
	
	vector<double> &Update(vector<double> &inputs);
	
};
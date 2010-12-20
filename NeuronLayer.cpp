/*
 *  NeuronLayer.cpp
 *  Nomlets
 *
 *  Created by Chris Cooper on 10-12-18.
 *  Copyright 2010 Chris Cooper. All rights reserved.
 *
 */

#include "NeuronLayer.h"

NeuronLayer::NeuronLayer(int _numNeurons, int inputsPerNeuron){
	
	numNeurons = _numNeurons;
	
	neurons.reserve(numNeurons);
	
	for (int i = 0; i < numNeurons; i++) {
		
		neurons.push_back(Neuron(inputsPerNeuron));
	}
}

vector<Neuron> &NeuronLayer::getNeurons(){
	return neurons;
}

int NeuronLayer::getNumNeurons(){
	return numNeurons;
}
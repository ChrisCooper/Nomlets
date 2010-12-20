/*
 *  NeuralNetwork.cpp
 *  Nomlets
 *
 *  Created by Chris Cooper on 10-12-18.
 *  Copyright 2010 Chris Cooper. All rights reserved.
 *
 */

#include "NeuralNetwork.h"

NeuralNet::NeuralNet(int _numInputs, int _numOutputs, int _numHiddenLayers, int _neuronsPerHiddenLayer) {
	numInputs = _numInputs;
	numOutputs = numOutputs;
	numHiddenLayers = _numHiddenLayers;
	neuronsPerHiddenLayer = _neuronsPerHiddenLayer;
	
	weightsNeedsUpdate = true;
}

void NeuralNet::fillNetwork(){
	
	//Create the layers of the network
	if (numHiddenLayers > 0) {
		
		for (int i = 0; i < numHiddenLayers; ++i) {
			if (i == 0){
				//Create first hidden layer which interfaces with inputs
				layers.push_back(NeuronLayer(neuronsPerHiddenLayer, numInputs));
			} else {
				layers.push_back(NeuronLayer(neuronsPerHiddenLayer, neuronsPerHiddenLayer));
			}
		}
		
		//Create output layer
		layers.push_back(NeuronLayer(numOutputs, neuronsPerHiddenLayer));
	}
	
	else {
		//Create output layer if it's the only layer
		layers.push_back(NeuronLayer(numOutputs, numInputs));
	}
}

vector<double> &NeuralNet::getWeights(){
	
	if (!weightsNeedsUpdate) {
		return weights;
	}
	
	//Layers
	for (int i = 0; i < numHiddenLayers + 1; i++) {
		
		//Neurons
		for (int j = 0; j < layers[i].getNumNeurons(); j++) {
			Neuron &neuron = (layers[i].getNeurons())[j];
			
			//Weights
			for (int k = 0; k < neuron.getNumInputs(); k++){
				vector<double> &weights = neuron.getWeights();
				weights.push_back(weights[k]);
			}
		}
	}
	
	return weights;
}

int NeuralNet::getNumWeights(){
	return getWeights().size();
}

void NeuralNet::setWeights(vector<double> &weights){

	weightsNeedsUpdate = true;
	int weightIndex = 0;

	//Layers
	for (int i = 0; i < numHiddenLayers + 1; i++) {
		
		//Neurons
		for (int j = 0; j < layers[i].getNumNeurons(); j++) {
			vector<double> actualWeights = (layers[i].getNeurons())[j].getWeights();
			 
			//Weights
			for (int k = 0; k < actualWeights.size(); k++){
				actualWeights[k] = weights[weightIndex];
			}
		}
	}
}

vector<double> &NeuralNet::Update(vector<double> &inputs){
	return weights;;
}

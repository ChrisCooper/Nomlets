/*
 *  NeuralNetwork.cpp
 *  Nomlets
 *
 *  Created by Chris Cooper on 10-12-18.
 *  Copyright 2010 Chris Cooper. All rights reserved.
 *
 */

#include "NeuralNetwork.h"
#include "Utilities.h"

NeuralNet::NeuralNet(int _numInputs, int _numOutputs, int _numHiddenLayers, int _neuronsPerHiddenLayer) {
	numInputs = _numInputs;
	numOutputs = numOutputs;
	numHiddenLayers = _numHiddenLayers;
	neuronsPerHiddenLayer = _neuronsPerHiddenLayer;
	
	weightsNeedsUpdate = true;
	
	fillNetwork();
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
				weightIndex++;
			}
		}
	}
}

vector<double> NeuralNet::Update(vector<double> &inputs){
	//stores the resultant outputs from each layer
	vector<double> outputs;
	
	int inputIndex = 0;
	
	//Confirm input size
	if (inputs.size() != numInputs) {
		return outputs;
	}
	
	//Layers
	for (int i = 0; i < numHiddenLayers + 1; i++) {
		
		if ( i > 0 ) {
			inputs = outputs;
		}
		
		outputs.clear();
		
		inputIndex = 0;
		
		vector<Neuron> neurons = layers[i].getNeurons();
		
		//Neurons
		for (int j = 0; j < neurons.size(); j++) {
			
			double netInput = 0;
			
			int	numInputs = neurons[j].getNumInputs();
			
			vector<double> weights = neurons[j].getWeights();
			
			//Weights
			for (int k = 0; k < numInputs - 1; k++) {
				
				netInput += weights[k] * inputs[inputIndex];
				inputIndex++;
			}
			
			//Subtract the bias
			netInput -= weights[numInputs-1];
			
			//Put activation value through Sigmoid function
			outputs.push_back(sigmoid(netInput, SIGMOID_CURVE_FLATNESS));
			
			inputIndex = 0;
		}
	}
	
	return outputs;
}

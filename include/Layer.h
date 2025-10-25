// Layer.h header file for Layer class
// *Header files describe the **interfaces** -> define what is available from classes
// e.g methods, attributes etc but doesnt actually implement their functions
#pragma once // ensure header is only included once at compilation

#include <vector> // include vectory library to use std::vector
// std::vector class is a dynamic array (e.g. a list)
#include <functional> // include standard functinoal lib for functions

class Layer{
    // Layer class: computes forward pass and backward pass for NN layer
    //      Attributes: num_inputs, num_neurons, weights, biases, pre-activation
    //                  output
    //      Methods: forward, backward
    //      Getters: getWeights, getBiases
    public: // public methods
    //constructor - initialise a Layer given inputs
    Layer(int num_inputs, int num_neurons, std::function<double(double)> activation_fn);
        // std::function<double(double)> declares a function wrapper with input double, output double
        // -> wrapper lets you pass any activation function flexibly
    
    // Methods:

    // forward pass through the constructed network
    std::vector<double> forward(const std::vector<double>& input);
    // ...& means only pass input --by reference-- which means it doesnt make a copy,
    // it is like a *pointer* -> directly modifies that variable -> more efficient
    // const -> tells compilier this is a constant-value variable and read-only

    // Getters:
    const std::vector<std::vector<double>>& getWeights() const { return weights; }
        // 1st const: caller cant modify the received value
        // 2nd const: this method itself, when defined, cannot modify the Layer object attrb
    const std::vector<double>& getBiases() const { return biases; }
    const std::vector<double>& getPreActivation() const { return pre_activation; }
    const std::vector<double>& getOutput() const { return output; }

 
    private: // private attributes
    int num_inputs; // number of inputs to the layer
    int num_neurons; // number of neurons/outputs in the layer
    std::vector<std::vector<double>> weights; // weights matrix for layer (2D vector)
    std::vector<double> biases; // biases vector for the layer (1D vector)
    std::vector<double> pre_activation; // pre-activation values (weighted sum + bias)
    std::function<double(double)> activation_fn; // activation function for the layer
    std::vector<double> output; // output of layer
};
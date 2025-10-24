// Layer.cpp implmenents the Layer class defined in Layers.h

#include "Layer.h" // include Layer.h header file from ..include/
#include <cstdlib> // include cstdlib for rand() for random initalisation of weights/biases
#include <random> // include random for rng

// Constructor Layer::Layer 
Layer::Layer(int num_inputs_, int num_neurons_, std::function<double(double)> activation_fn_)
    : num_inputs(num_inputs_), num_neurons(num_neurons_), activation_fn(activation_fn_)
    // initiliaser list above -> sets the private attributes - more efficient that setting 
    // inside the constructor body
    { // CONSTRUCTOR
    // initialise the weights and biases sizes
    weights.resize(num_neurons, std::vector<double>(num_inputs)); // this sets the size of outer vector (rows)
    // this means the 2D vector is not contiguous in memory -> otherwise flatten the 2d vector to be faster
    biases.resize(num_neurons); // biases is a 1D vector of size num_neurons

    // intialise pre activation and output vectors
    pre_activation.resize(num_neurons);
    output.resize(num_neurons);

    // create a random unifrom distribution using rng
    std::random_device rd; // get random integer from system hardware each time
    std::mt19937 gen(rd()); // random number generator with seed from rd() - Mersenne Twister algorithm
    std::uniform_real_distribution<> dist(-1.0, 1.0); // uniform distribution between -1 and 1 (<> mean default double)
    
    // random weights and biases
    for(int i = 0; i < num_neurons; ++i){ // ++i is pre-increment that increments first before returning -> slightly more efficient
        for(int j = 0; j < num_inputs; ++j){
            weights[i][j] = dist(gen); // assign random weight from uniform distribution to i,j
        }
        biases[i] = dist(gen); // assign random bias
    }

    }
    // Method: forward
    std::vector<double> Layer::forward(const std::vector<double>& input){ // Layer::forward - forward belongs to layer class
        // compute pre-activation
        for(int i =0; i<num_neurons; ++i){ // for each neuron
            pre_activation[i] = biases[i]; // start with bias
            for(int j=0; j<num_inputs;++j){ // for each input
                pre_activation[i] += weights[i][j] * input[j]; // weighted sum of inputs using layer weights
            }
            output[i] = activation_fn(pre_activation[i]); // apply activation fn
        }
        return output; // return output vector
    }
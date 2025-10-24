// Network class header file
#pragma once

#include <vector>
#include <functional>
#include "Layer.h"

class Network{ // Network class: constructs a neural network with multiple layers
    public:
        // Constructor: takes in vector of layer sizes and activation functions (different for each layer)
        Network(const std::vector<int>& layer_sizes, const std::vector<std::function<double(double)>>& activation_fns);
        
        // Method: forward pass through the network
        std::vector<double> forward(const std::vector<double>& input);

        // Getter: getLayers
        const std::vector<Layer>& getLayers() const { return layers; }

    private:
        std::vector<Layer> layers; // vector of Layer objects for each layer
}; // remember the semicolor after class def
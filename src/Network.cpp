// Network class implementation file

#include "Network.h" // include Network.h header file

Network::Network(const std::vector<int>& layer_sizes, const std::vector<std::function<double(double)>>& activation_fns){
    //Constructor: create layers (layers is an attribute of Network class)
    for (size_t i=1; i<layer_sizes.size() - 1; ++i){ //size_t is unsigned int type useful for sizes
        layers.emplace_back(Layer(layer_sizes[i-1], layer_sizes[i], activation_fns[i-1])); // create Layer object and to layers vector
    } // emplace_back constructs Layer in place -> more efficient than push back
}

// Method: forward
std::vector<double> Network::forward(const std::vector<double>& input){
    std::vector<double> out = input; //start with input
    for(auto& layer : layers){ // for each layer in layers
        out = layer.forward(out); // forward pass through layer
    };
    return out; // return final output
}
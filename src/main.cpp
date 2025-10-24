#include "Layer.h"
#include "Network.h"
#include <iostream>
#include <cmath> // for activation function

double relu(double x){ // ReLU activation fn
    return x>0 ? x : 0;  // if x>0 return x, else return 0
}

int main(){
    // create a network with 2 inputs, 3 neurons in hidden layer, 1 output
    std::vector<int> layer_sizes = {2, 3, 1}; // 2 inputs, 3 hidden neurons, 1 output
    std::vector<std::function<double(double)>> activation_fns = {relu, relu}; // ReLU for both layers
    Network net(layer_sizes, activation_fns); // create Network object

    // sample input
    std::vector<double> input = {0.5, -0.2};

    // forward pass
    auto output = net.forward(input); // auto figures out data type

    // print output
    std::cout << "Layer output: ";
    for(const auto& val : output){ // range-based for loop
        std::cout << val << " ";
    }
    std::cout << std::endl;
    return 0;
}
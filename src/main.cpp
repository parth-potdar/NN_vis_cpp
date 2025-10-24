#include "Layer.h"
#include <iostream>
#include <cmath> // for activation function

double relu(double x){ // ReLU activation fn
    return x>0 ? x : 0;  // if x>0 return x, else return 0
}

int main(){
    // create layer
    Layer layer(2, 5, relu);

    // sample input
    std::vector<double> input = {0.5, -0.2};

    // forward pass
    auto output = layer.forward(input); // auto figures out data type

    // print output
    std::cout << "Layer output: ";
    for(const auto& val : output){ // range-based for loop
        std::cout << val << " ";
    }
    std::cout << std::endl;
    return 0;
}
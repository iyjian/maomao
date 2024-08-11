#include <functional>
#include <iostream>
#include <cmath>

const double EPSILON = 1e-4;

double f(double x){
    return std::abs(x + 1) + std::abs(x - 6) + 2 * std::abs(x + 1.5);
}

double derivative(std::function<double(double)> f, double x, double delta = 1e-4){
    return (f(x + delta) - f(x)) / delta;
}

double findMinimumOfFunction(std::function<double(double)> f, double learningRate = 1e-5){
    double x0 = 2;

    while(std::abs(derivative(f, x0)) > EPSILON){
        x0 -= learningRate * derivative(f, x0);
    }

    return f(x0);
}

int main(){
    std::cout << findMinimumOfFunction(f) << std::endl;
}


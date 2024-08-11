#include <functional>
#include <iostream>

const double EPSILON = 1e-4;

double f(double x){
    return (2 * x * x + 3 * x + -1);
}

double derivative(std::function<double(double)> f, double x, double delta = 1e-4){
    return (f(x + delta) - f(x)) / delta;
}

double findMinimumOfFunction(std::function<double(double)> f, double learningRate = 1e-5){
    double x0 = 2;

    while(abs(derivative(f, x0)) > EPSILON){
        x0 -= learningRate * derivative(f, x0);
        // std::cout << x0 << std::endl;
        printf("%.2f, %.2f, %f, %d\n", x0, abs(derivative(f, x0)), EPSILON, abs(derivative(f, x0)) > EPSILON);
    }

    return x0;
}

int main(){
    std::cout << findMinimumOfFunction(f) << std::endl;
}


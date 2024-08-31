#include <functional>
#include <cmath>

const double EPSILON = 1e-4;

double f(double a, double b, double x){
    return a * x + b;
}

double derivative_of_first_arguement(std::function<double(double, double)> f, double x, double y, double delta = EPSILON){
    return (f(x + delta, y) - f(x, y)) / delta;
}

double derivative_of_second_arguement(std::function<double(double, double)> f, double x, double y, double delta = EPSILON){
    return (f(x, y + delta) - f(x, y)) / delta;
}

double examples_arguement[3] = {1, 2, 3};
double examples_answer[3] = {8.1, 10.9, 14.2};

double* find_minimum_of_two_variable_expresstion(std::function<double(double, double)> f, double learning_rate = 1e-5){
    double x0, y0;

    while(std::abs(derivative_of_first_arguement(x0, y0)) > EPSILON){
        x0 -= derivative_of_first_arguement(x0, y0) * learning_rate;
    }
    while(std::abs(derivative_of_second_arguement(x0, y0)) > EPSILON){
        y0 -= derivative_of_second_arguement(x0, y0) * learning_rate;
    }
    return {x0, y0}

}

double loss(std::function<double(double, double, double)> f, double a, double b, double x, double result){
    return std::pow(f(a, b, x) - result, 2);
}

double* guess_arguements(std::function<double(double, double)> f, double examples_arguement[3], double examples_answer[3], double learning_rate = 1e-5){
    double a, b;
    
    while()
}
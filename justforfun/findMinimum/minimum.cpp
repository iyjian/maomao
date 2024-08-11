#include <functional>
#include <exception>
#include <iostream>
#include <new>

// bool slope(std::function<double(double)> f, double x0, double x1){
// }


double f(double x){
    return (x * x - 2.0 * x + 1.0);
}

double findMinimumOfQuadraticEqution(std::function<double(double)> f){
    double x = 0.00;
    double delta = 1e-4;
    double x1 = x + delta;
    double x2 = x - delta;
    while((f(x1) > f(x) && f(x2) > f(x)) != true){
        if(f(x1) < f(x)){
            x = x1;
        }
        else if(f(x2) < f(x)){
            x = x2;
        }
        else{
            continue;
        }
        double x1 = x + delta;
        double x2 = x - delta;
        std::cout << x << std::endl;
    }
    return f(x);
}

int main(){
    std::cout << findMinimumOfQuadraticEqution(f) << std::endl;
}

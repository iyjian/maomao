#include <iostream>
#include <cmath>

bool isInLine(double x1) {
    return (std::pow(0.5 - x1, 2) * 2) <= std::pow(0.5, 2);
}

double sqrt2_computing(int Precision) {
    int counter = 0;
    int totalRolls = 0;
    int inLineTimes = 0;

    while (counter < Precision) {
        double x = counter / Precision;
        if (isInLine(x)) {
            inLineTimes++;
        }
        totalRolls++;
        counter++;
    }
    return static_cast<double>(totalRolls) / inLineTimes;
}

int main() {
    int Precision = 1000000; 
    double sqrt2_approx = sqrt2_computing(Precision);
    std::cout << "Approximate value of sqrt(2): " << sqrt2_approx << std::endl;
    return 0;
}
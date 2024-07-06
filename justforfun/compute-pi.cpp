#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

// Function to generate a random float between 0 and 1
double randDouble() {
    return double(rand()) / RAND_MAX;
}

// Function to generate a random 2D point
std::pair<double, double> rand2DPoint() {
    return {randDouble(), randDouble()};
}

// Function to check if a point is inside the quarter-circle
bool isInCircle(double x1, double y1) {
    return (0.5 - x1) * (0.5 - x1) + (0.5 - y1) * (0.5 - y1) <= 0.5 * 0.5;
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Initialize random seed

    int totalRolls = 0;
    int inCircleTimes = 0;

    while (totalRolls < 1000000000) {
        auto point = rand2DPoint();
        if (isInCircle(point.first, point.second)) {
            inCircleTimes++;
        }
        totalRolls++;
    }

    std::cout << (4.0 * inCircleTimes) / totalRolls << std::endl; // Area approximation

    return 0;
}
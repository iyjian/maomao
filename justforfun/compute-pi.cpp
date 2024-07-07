#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

bool isInCircle(double x1, double y1) {
    return (0.5 - x1) * (0.5 - x1) + (0.5 - y1) * (0.5 - y1) <= 0.5 * 0.5;
}

std::pair<double, double> rand2DPoint() {
    return {static_cast<double>(rand()) / RAND_MAX, static_cast<double>(rand()) / RAND_MAX};
}

double pi_computing_stable_version(int Precision) {
    int grids = Precision;
    int totalRolls = 0;
    int inCircleTimes = 0;
    int counter = 0;

    while (counter < grids * grids) {
        double x = (counter % grids) / grids;
        double y = (counter / grids) / grids;
        if (isInCircle(x, y)) {
            inCircleTimes++;
        }
        totalRolls++;
        counter++;
    }

    return (4.0 * inCircleTimes) / totalRolls;
}

double pi_computing_random_version(int Precision) {
    int totalRolls = 0;
    int inCircleTimes = 0;

    while (totalRolls < Precision) {
        auto point = rand2DPoint();
        if (isInCircle(point.first, point.second)) {
            inCircleTimes++;
        }
        totalRolls++;
    }

    return (4.0 * inCircleTimes) / totalRolls;
}

int main(){
    // do the things you want
}
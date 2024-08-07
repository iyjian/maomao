#include <iostream>
#include <cmath>
#include <random>
#include <cstdlib>
#include <ctime>

unsigned long long factorial(unsigned int n){
    if(n == 0){
        return 1;
    }
    unsigned long long result = 1;
    for(int i = 1; i <= n; i++){
        result *= i;
    }
    return result;
}

bool isPrime(int num){
    for (int i = 2; i <= sqrt(num); i ++){
        if (num % i == 0){
            return false;
        }
    }
    return true;
}

unsigned int randint(int min, int max){
    srand(time(NULL));
    return rand() % (max - min + 1) + min;
}


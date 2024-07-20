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

bool checkPrimeNumber(unsigned int num) {
    if (num == 1) {
        return false;
    }
    for (int maybe_factor = 2; maybe_factor <= std::ceil(num / 2.0); maybe_factor ++) {
        if (num % maybe_factor == 0) {
            return false; 
        }
    }
    return true;
}


bool isPrime (int num){
    for (int i = 2; i <= sqrt(num); i ++){
        if (num % i == 0){
            return false;
        }
    }
    return true;
}

unsigned int random_number(int min, int max){
    srand(time(NULL));
    return rand() % (max - min + 1) + min;
}

int main(){
    std::cout << checkPrimeNumber(7) << std::endl;
}
#include <iostream>
#include <cmath>

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

int main(){
    std::cout << checkPrimeNumber(7) << std::endl;
}
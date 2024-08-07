#include <random>
#include <vector>
#include <cmath>
using std::vector;

// unsigned long long randint(unsigned long long min, unsigned long long max){
    // std::random_device rd;
    // std::mt19937 gen(rd());
    // std::uniform_int_distribution<> distr(min, max);
//     return distr(gen);
// }

bool isPrime(int num){
    for (int i = 2; i <= sqrt(num); i ++){
        if (num % i == 0){
            return false;
        }
    }
    return true;
}








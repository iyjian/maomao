#include <random>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>
using std::vector;
using boost::multiprecision::cpp_int;

bool isPrime(cpp_int num){
    if(num == 1) return false;
    for (int i = 2; i <= boost::multiprecision::sqrt(num); i++){
        if (num % i == 0) return false;
    }
    return true;
}

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

vector<bool> rand_very_big_odd_num(int bit) {
    std::mt19937 mt(std::random_device{}());
    std::uniform_int_distribution<> distr(0, 1);

    vector<bool> random_result = {1};
    for (int i = 1; i < bit - 1; i++) {
        random_result.push_back(distr(mt));
    }

    random_result.push_back(1);
    return random_result;
}



cpp_int rand_prime(int bit){
    std::random_device random;
    std::mt19937 mt(random());
    std::uniform_int_distribution<> distribution_for_first_number(2 ^ 9, 2 ^ 10);
    int m = distribution_for_first_number(mt);
    int n = m + 1;

    std::uniform_int_distribution<> distr_for_bits(0, 1);
    cpp_int prime_maybe;
    vector<cpp_int> not_prime_list;
    do{
        std::random_device rd;
        std::mt19937 gen(rd());
        for(int i = 0; i < 1000; i++){
            prime_maybe += distr_for_bits(gen) << i;
        }
        prime_maybe = prime_maybe * n + m;
        if(std::find(not_prime_list.begin(), not_prime_list.end(), (prime_maybe)) != not_prime_list.end()) continue;
        not_prime_list.push_back(prime_maybe);
    }
    while(isPrime(prime_maybe) == false);
    not_prime_list.clear();
    return prime_maybe;
}


int main(){
    // std::cout << randPrime() << std::endl;
}
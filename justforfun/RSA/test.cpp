#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>
#include <random>
#include <array>
using boost::multiprecision::cpp_int;
using std::array;


cpp_int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

cpp_int rand_very_big_odd_num(int bit) {
    std::mt19937 mt(std::random_device{}());
    std::uniform_int_distribution<> distr(0, 1);

    cpp_int random_result = 1;
    for (int i = 1; i < bit - 1; i++) {
      cpp_int bit_value = distr(mt);
      random_result += bit_value << i;
    }

    return random_result += (1 << bit);
}

cpp_int mod_pow(cpp_int base, cpp_int power_num, cpp_int mod_num){
    base %= mod_num;
    cpp_int x = base;
    for(cpp_int i = 1; i < power_num; i++){
        base = (base * x) % mod_num;
    }
    return base;
}

// bool is_prime_checking_invalid = false;

// bool miller_rabbin(cpp_int num_for_check){
//     // rand a num and gcd(rand_num, num_for_check) = 1
//     // we can sppose that num_for_check is a prime
//     std::mt19937_64 mt_64(std::random_device{}());
//     std::uniform_int_distribution<> dis(20, (2 << 63));
//     cpp_int a = dis(mt_64);
//     if((gcd(a, num_for_check) == true) || (mod_pow(a, (num_for_check - 1), num_for_check) != 1)) return false;
//     cpp_int x = num_for_check - 1;
//     int s;
//     while(x % 2 == 0){
//         x %= 2;
//         s++;
//     }
//     if(s == 0) return false;
    
//     // x is our start point
//     cpp_int mod_pow_result = mod_pow(a, x, num_for_check);
//     if(mod_pow_result == 1 || mod_pow_result == (num_for_check - 1)){
//         is_prime_checking_invalid = true;
//         return false;
//     }
//     bool is_appeared = false;


// }

int main(){
    cpp_int a("6553765537655376553765537655372222222211133");
    cpp_int b("100000000000000000000000000000");
    cpp_int c("33333333333333333333333");
    // mod_pow(a, b, c);
    boost::multiprecision::pow(a, b);
}
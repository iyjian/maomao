#include <boost/random.hpp>
#include <boost/multiprecision/number.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <vector>
#include <iostream>
using int_4096 = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<4096, 4096, boost::multiprecision::unsigned_magnitude, boost::multiprecision::checked, void>>;

std::vector<int_4096> find_factor_of_2(int_4096 n){
    int_4096 s = 0;
    while(n % 2 == 0){
        n /= 2;
        s++;
    }
    return {s, n};
}

bool is_prime(int_4096 p, int_4096 n){
    std::vector<int_4096> factors = find_factor_of_2(p - 1);

    int_4096 s = factors[0];
    int_4096 k = boost::multiprecision::powm(n, factors[1], p);
    
    for(int i = 0; i < s; i++){
        if(k == (p - 1)){
            return true;
        }
        else if(k == 1){
            return false;
        }
        k = boost::multiprecision::powm(k, 2, p);
    }
    return false;

}

int main(){
    // int_4096 p = boost::multiprecision::pow(2, 127) - 1;

    // std::cout << boost::multiprecision::powm(11, p - 1, p) << std::endl;
    std::cout << is_prime(int_4096(10019627), 11) << std::endl;
    return 0;
}
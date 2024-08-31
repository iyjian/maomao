#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>
#include <vector>
#include <random>
using boost::multiprecision::cpp_int;
using std::cout;
using std::endl;
using std::vector;


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

cpp_int mod_pow_of_two(cpp_int base, unsigned int pow_num, cpp_int mod_num){
    // to compute (base ** (2 ** pow_num)) % mod_num
    
}

// cpp_int mod_pow(cpp_int base, vector<bool> binary_or_num, cpp_int mod_num){
//     base %= mod_num;
//     cpp_int result = 1;
//     const unsigned int size = binary_or_num.size();
//     for(unsigned int i = 0; i < size; i++){
//         result = result * 
//     }
// }

int main(){
    for(bool i : rand_very_big_odd_num(20)){
        printf("%d ", int(i));
    }
    printf("\n");
}
#include <string>
#include <algorithm>
#include <iostream>
using std::string;
using std::reverse;

// struct big_int{
//     string data;
//     big_int operator+(const big_int& a) const{

//     }
// };

string plas(string a, string b){
    bool carry = 0;
    u_int8_t a_current;
    u_int8_t b_current;
    u_int8_t sum_current;
    string result;
    for(size_t i = a.size() - 1; i >= 0; i--){
        a_current = u_int8_t(a.back() - '0');
        b_current = u_int8_t(b.back() - '0');
        sum_current = a_current + b_current + carry;
        carry = sum_current >= 10;
        sum_current %= 10;
        result.push_back(char(sum_current + '0'));
        printf("1");
    }
    result.push_back(carry);
    reverse(result.begin(), result.end());
    return result;
}

int main(){
    string a = plas("97", "89");
    std::cout << a << std::endl;
}
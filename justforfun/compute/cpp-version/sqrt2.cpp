#include <chrono>
#include <iostream>
#include <boost/multiprecision/cpp_dec_float.hpp>

int main(){
    typedef boost::multiprecision::number<boost::multiprecision::cpp_dec_float<50>, boost::multiprecision::et_off> dec_float_50;
    double a = 1;
    a /= 9;
    std::cout << a <<std::endl;
}
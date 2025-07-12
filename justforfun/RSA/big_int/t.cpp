#include <chrono>
#include <iostream>
#include "big_int_v2.hpp"

int main(){
    big_int<1024> a;
    auto start = std::chrono::high_resolution_clock::now();
    
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << std::endl;
    a.delete_big_int();
}
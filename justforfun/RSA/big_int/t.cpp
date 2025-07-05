#include <iostream>
#include <climits>
#include <cmath>


int main(){
    std::cout << 2147483658 + 2147483654 - UINT_MAX - 1 << std::endl;
}

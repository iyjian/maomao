#include <iostream>
#include <climits>
#include <cmath>
#include <bitset>

int main(){
    int* data = new int[10];
    data = {0b00000000, 0b00000001, 0b00000010, 0b00000011, 0b00000100, 0b00000101, 0b00000110, 0b00000111, 0b00001000, 0b00001001};
    data<<1;
    std::cout << "data: ";
    for(size_t i = 0; i < 10; i++){
        std::cout << std::bitset<sizeof(int) * 8>(data[i]);
    }
    std::cout << std::endl;
}

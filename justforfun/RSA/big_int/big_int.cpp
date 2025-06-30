#include <iostream>
#include <cstdlib>
#include <string>

template <unsigned int bits_of_number>
class big_int{
    private:
        
    public:
        const unsigned int bits = bits_of_number;
        unsigned int data_limit = bits_of_number / (sizeof(unsigned int));
        unsigned int* data = (unsigned int*)malloc(bits_of_number / 8);
        void set_data(unsigned int num, unsigned int place);
        bool operator==(const big_int<bits_of_number> & int_1,  big_int<bits_of_number> & int_2);
        bool operator!=(const big_int<bits_of_number> & int_1,  big_int<bits_of_number> & int_2);
        bool operator<(const big_int<bits_of_number> & int_1,  big_int<bits_of_number> & int_2);
        bool operator<=(const big_int<bits_of_number> & int_1,  big_int<bits_of_number> & int_2);
        bool operator>(const big_int<bits_of_number> & int_1,  big_int<bits_of_number> & int_2);
        bool operator>=(const big_int<bits_of_number> & int_1,  big_int<bits_of_number> & int_2);
        big_int<bits_of_number> operator+(const big_int<bits_of_number> & int_1,  big_int<bits_of_number> & int_2);
        big_int<bits_of_number> operator-(const big_int<bits_of_number> & int_1,  big_int<bits_of_number> & int_2);
        big_int<bits_of_number> operator*(const big_int<bits_of_number> & int_1,  big_int<bits_of_number> & int_2);
        big_int<bits_of_number> operator/(const big_int<bits_of_number> & int_1,  big_int<bits_of_number> & int_2);
        big_int<bits_of_number> operator%(const big_int<bits_of_number> & int_1,  big_int<bits_of_number> & int_2);
        big_int<bits_of_number> operator^(const big_int<bits_of_number> & int_1,  big_int<bits_of_number> & int_2);
        big_int<bits_of_number> operator<<(const big_int<bits_of_number> & int_1,  big_int<bits_of_number> & int_2);
        big_int<bits_of_number> operator>>(const big_int<bits_of_number> & int_1,  big_int<bits_of_number> & int_2);
        big_int<bits_of_number> power_mod(const big_int<bits_of_number> & base, const big_int<bits_of_number> & exponent, const big_int<bits_of_number> & modulus);
};

big_int<bits_of_number>::set_data(unsigned int num, unsigned int place){
    if(place >= data_limit){
        std::cerr << "Error: Place out of bounds." << std::endl;
        return;
    }
    data[place] = num;
}

bool big_int<bits_of_number>::operator==(const big_int<bits_of_number> & int_1,  big_int<bits_of_number> & int_2){
    if(int_1.data_limit != int_2.data_limit){
        std::cerr << "Error: data limits do not match." << std::endl;
        return false;
    }
    for(int i = int_1.data_limit; i > 0; i++){
        if(int_1.data[i] != int_2.data[i]) return false;
    }
    return true;
}

bool big_int<bits_of_number>::operator!=(const big_int<bits_of_number> & int_1,  big_int<bits_of_number> & int_2){
    return !(int_1 == int_2);
}

bool big_int<bits_of_number>::operator<(const big_int<bits_of_number> & int_1,  big_int<bits_of_number> & int_2){
    if(int_1.data_limit != int_2.data_limit){
        std::cerr << "Error: data limits do not match." << std::endl;
        return false;
    }
    for(int i = int_1.data_limit; i > 0; i--){
        if(int_1.data[i] < int_2.data[i]) return true;
        else if(int_1.data[i] > int_2.data[i]) return false;
    }
    return false;
}

bool big_int<bits_of_number>::operator<=(const big_int<bits_of_number> & int_1,  big_int<bits_of_number> & int_2){
    return !(int_1 < int_2);
}

bool big_int<bits_of_number>::operator>(const big_int<bits_of_number> & int_1,  big_int<bits_of_number> & int_2){
    return int_2 < int_1;
}

bool big_int<bits_of_number>::operator>=(const big_int<bits_of_number> & int_1,  big_int<bits_of_number> & int_2){
    return int_2 <= int_1;
}

big_int<bits_of_number> big_int<bits_of_number>::operator+(const big_int<bits_of_number> & int_1,  big_int<bits_of_number> & int_2){
    if(int_1.data_limit != int_2.data_limit){
        std::cerr << "Error: data limits do not match." << std::endl;
        return 0;
    }
    big_int<int_1.bits> result;
    bool carry = 0;
    for(int i = 0; i < int_1.data_limit; i++){

    }

}

int main(){
//     int* location =  (int*)malloc(512);
//     if (location == NULL){
//         std::cerr << "Memory allocation failed!" << std::endl;
//         return 1;
//     }
//     location[0] = 100;
//     location[1] = 200;
//     std::cout << location << std::endl;
//     std::cout << location[1] << std::endl;
//     free(location);
}
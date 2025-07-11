#include <iostream>
#include <cstdlib>
#include <string>
#include <climits>
#include <random>
#include <bitset>

template <const unsigned int bits_of_number>
class big_int{
    private:
        
    public:
        static constexpr size_t data_limit = floor((floor(bits_of_number / 8) + 1) * 8 / sizeof(unsigned int));
        unsigned int* data = new unsigned int[data_limit];
        void set_data(size_t place, unsigned int num);
        bool operator==(const big_int<bits_of_number> & b);
        bool operator!=(const big_int<bits_of_number> & b);
        bool operator<(const big_int<bits_of_number> & b);
        bool operator<=(const big_int<bits_of_number> & b);
        bool operator>(const big_int<bits_of_number> & b);
        bool operator>=(const big_int<bits_of_number> & b);
        big_int<bits_of_number> operator+(const big_int<bits_of_number> & b);
        void operator+=(const big_int<bits_of_number> & b);
        void operator++();
        // big_int<bits_of_number> operator*(const big_int<bits_of_number> & b);
        // big_int<bits_of_number> operator/(const big_int<bits_of_number> & b);
        // big_int<bits_of_number> operator%(const big_int<bits_of_number> & b);
        // big_int<bits_of_number> operator^(const big_int<bits_of_number> & b);
        // big_int<bits_of_number> operator<<(const big_int<bits_of_number> & b);
        // big_int<bits_of_number> operator>>(const big_int<bits_of_number> & b);
        // big_int<bits_of_number> power_mod(const big_int<bits_of_number> & base, const big_int<bits_of_number> & exponent, const big_int<bits_of_number> & modulus);

        big_int(){
            if(data == nullptr) throw std::runtime_error("Memory alloc failed.");
            for(size_t i = 0; i < data_limit; i++) data[i] = 0;
        }
        ~big_int(){
            delete(data);
            data = nullptr;
        }
};

template <const unsigned int bits_of_number>
void big_int<bits_of_number>::set_data(size_t place, unsigned int num){
    if(place >= data_limit){
        std::cerr << "Error: Place out of bounds." << std::endl;
        return;
    }
    data[place] = num;
}

template <const unsigned int bits_of_number>
bool big_int<bits_of_number>::operator==(const big_int<bits_of_number> & b){
    if(this->data_limit != b.data_limit){
        std::cerr << "Error: data limits do not match." << std::endl;
        return false;
    }
    for(int i = 0; i < this->data_limit; i++){
        if(this->data[i] != b.data[i]) return false;
    }
    return true;
}

template <const unsigned int bits_of_number>
bool big_int<bits_of_number>::operator!=(const big_int<bits_of_number> & b){
    return !(this->data == b.data);
}

template <const unsigned int bits_of_number>
bool big_int<bits_of_number>::operator<(const big_int<bits_of_number> & b){
    if(this->data_limit != b.data_limit){
        std::cerr << "Error: data limits do not match." << std::endl;
        return false;
    }
    for(int i = 0; i < this->data_limit; i++){
        if(this->data[i] < b.data[i]) return true;
        else if(this->data[i] > b.data[i]) return false;
    }
    return false;
}

template <const unsigned int bits_of_number>
bool big_int<bits_of_number>::operator<=(const big_int<bits_of_number> & b){
    return !(this->data > b.data);
}

template <const unsigned int bits_of_number>
bool big_int<bits_of_number>::operator>(const big_int<bits_of_number> & b){
    return b < this;
}

template <const unsigned int bits_of_number>
bool big_int<bits_of_number>::operator>=(const big_int<bits_of_number> & b){
    return b <= this;
}

template <const unsigned int bits_of_number>
big_int<bits_of_number> big_int<bits_of_number>::operator+(const big_int<bits_of_number> & b){
    if(this->data_limit != b.data_limit){
        throw std::invalid_argument("Error: data limits do not match.");
    }
    if(this->data == nullptr || b.data == nullptr){
        throw std::invalid_argument("Error: data is not defined, please set data first with set_data() function.");
    }
    
    big_int<bits_of_number> result;
    bool carry = 0;
    unsigned int temp;
    for(int i = (this->data_limit - 1); i >= 0; i--){
        temp = this->data[i] + b.data[i] + (unsigned int)(carry);
        if(temp < this->data[i]){
            carry = 1;
            temp -= UINT_MAX + 1;
        }
        else{
            carry = 0;
        }
        result.data[i] = temp;
    }
    return result;
}

template <const unsigned int bits_of_number>
void big_int<bits_of_number>::operator+=(const big_int<bits_of_number> & b){
    this + b;
}

template <const unsigned int bits_of_number>
void big_int<bits_of_number>::operator++(){
    this += 1;
}

int main(){
    big_int<32> a;
    big_int<32> b;
    a.set_data(a.data_limit - 1, 0b10000000000000000000000000001010);
    std::cout << "a: " << a.data[0] << std::endl;
    // std::cout << "a.data_limit: " << a.data_limit << std::endl;
    b.set_data(b.data_limit - 1, 0b10000000000000000000000000000110);
    std::cout << "b: " << b.data[0] << std::endl;
    big_int<32> c = a + b;
    std::cout << "result: ";
    for(size_t i = 0; i < c.data_limit; i++){
        std::cout << std::bitset<sizeof(unsigned int) * 8>(c.data[i]);
    }
    std::cout << std::endl;
    a.~big_int();
    b.~big_int();
    c.~big_int();
    return 0;
}
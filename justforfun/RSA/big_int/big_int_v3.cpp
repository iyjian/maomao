#include <iostream>
#include <climits>
#include <cmath>
#include <bitset>
#define SIZEOF_UNSIGNED_INT sizeof(unsigned int)
#define BITS_OF_UNSIGNED_INT (SIZEOF_UNSIGNED_INT * 8)

template <const unsigned int bits>
class big_int{
    private:
        
    public:
        static constexpr size_t limit = std::floor((std::floor(bits / 8) + 1) * 8 / SIZEOF_UNSIGNED_INT) + 1;
        unsigned int* number = new unsigned int[limit];
        
        bool operator==(const big_int<bits> & b);
        bool operator!=(const big_int<bits> & b);
        bool operator<(const big_int<bits> & b);
        bool operator<=(const big_int<bits> & b);
        bool operator>(const big_int<bits> & b);
        bool operator>=(const big_int<bits> & b);

        void operator+=(const big_int<bits> & b);
        void operator++();

        void operator=(const char* number);
        big_int<bits> operator+(const big_int<bits> & b);
        // big_int<bits> operator*(const big_int<bits> & b);
        // big_int<bits> operator%(const big_int<bits> & b);
        // big_int<bits> operator^(const int & b);
        big_int<bits> operator<<(const size_t & b);
        // big_int<bits> operator>>(const size_t & b);
        // big_int<bits> power_mod(const big_int<bits> & base, const int & exponent, const big_int<bits> & modulus);

        bool read(size_t place);
        void write(size_t place, bool value);

        big_int(){
            if(number == nullptr) throw std::runtime_error("Memory alloc failed.");
            for(size_t i = 0; i < limit; i++) number[i] = 0;
        }
};



template <const unsigned int bits>
bool big_int<bits>::operator==(const big_int<bits> & b){
    if(this->limit != b.limit){
        std::cerr << "Error: number limits do not match." << std::endl;
        return false;
    }
    for(int i = 0; i < this->limit; i++){
        if(this->number[i] != b.number[i]) return false;
    }
    return true;
}

template <const unsigned int bits>
bool big_int<bits>::operator!=(const big_int<bits> & b){
    return !(this->number == b.number);
}

template <const unsigned int bits>
bool big_int<bits>::operator<(const big_int<bits> & b){
    if(this->limit != b.limit){
        std::cerr << "Error: number limits do not match." << std::endl;
        return false;
    }
    for(int i = 0; i < this->limit; i++){
        if(this->number[i] < b.number[i]) return true;
        else if(this->number[i] > b.number[i]) return false;
    }
    return false;
}

template <const unsigned int bits>
bool big_int<bits>::operator<=(const big_int<bits> & b){
    return !(this->number > b.number);
}

template <const unsigned int bits>
bool big_int<bits>::operator>(const big_int<bits> & b){
    return b < this;
}

template <const unsigned int bits>
bool big_int<bits>::operator>=(const big_int<bits> & b){
    return b <= this;
}

template <const unsigned int bits>
big_int<bits> big_int<bits>::operator+(const big_int<bits> & b){
    big_int<bits> result;
    bool carry = 0;
    unsigned int temp;
    for(int i = (this->limit - 1); i >= 0; i--){
        temp = this->number[i] + b.number[i] + (unsigned int)(carry);
        if(temp < this->number[i]){
            carry = 1;
            temp -= UINT_MAX + 1;
        }
        else{
            carry = 0;
        }
        result.number[i] = temp;
    }
    return result;
}

template <const unsigned int bits>
void big_int<bits>::operator+=(const big_int<bits> & b){
    unsigned int carry = 0;
    unsigned int temp;
    for(int i = (this->limit - 1); i >= 0; i--){
        temp = this->number[i] + b.number[i] + carry;
        if(temp < this->number[i]){
            carry = 1;
            temp -= UINT_MAX + 1;
        }
        else{
            carry = 0;
        }
        this->number[i] = temp;
    }
    delete(&carry);
    delete(&temp);
}

template <const unsigned int bits>
void big_int<bits>::operator++(){
    this += 1;
}

template <const unsigned int bits>
void big_int<bits>::write(size_t place, bool value){
    number[size_t(limit - std::floor(place / BITS_OF_UNSIGNED_INT) - 1)] += (value << int(place % BITS_OF_UNSIGNED_INT));
}

template <const unsigned int bits>
bool big_int<bits>::read(size_t place){
    unsigned int temp = place % BITS_OF_UNSIGNED_INT - 1;
    return bool((number[size_t(limit - std::floor(place / (BITS_OF_UNSIGNED_INT)) - 1)] & (1 << temp)) >> temp);
}

template <const unsigned int bits>
big_int<bits> big_int<bits>::operator<<(const size_t & b){
    big_int<bits> result;
    for(size_t digit = 0; digit < (this->limit * BITS_OF_UNSIGNED_INT) - b; digit++){
        result.write(digit + b - 1, this->read(digit));
    }
    return result;
}

int main(){
    big_int<64> a;
    a.number[a.limit - 1] = 0b01101101001100111001101011100100;
    a.number[a.limit - 2] = 0b01001100101011001001100101100101;
    // for(int i = 1; i <= 32; i++){
    //     a.read(i);
    // }
    // std::cout << std::endl;
    std::cout << std::bitset<BITS_OF_UNSIGNED_INT>(a.number[a.limit - 2]) << std::bitset<BITS_OF_UNSIGNED_INT>(a.number[a.limit - 1]) << std::endl;
    a = a << 8;
    std::cout << std::bitset<BITS_OF_UNSIGNED_INT>(a.number[a.limit - 2]) << std::bitset<BITS_OF_UNSIGNED_INT>(a.number[a.limit - 1]) << std::endl;
}
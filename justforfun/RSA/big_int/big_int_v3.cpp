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
        
        bool operator==(const big_int<bits> & b) const;
        bool operator!=(const big_int<bits> & b) const;
        bool operator<(const big_int<bits> & b) const;
        bool operator<=(const big_int<bits> & b) const;
        bool operator>(const big_int<bits> & b) const;
        bool operator>=(const big_int<bits> & b) const;

        void operator+=(const big_int<bits> & b);
        void operator++();

        big_int<bits> operator+(const big_int<bits> & b) const;
        big_int<bits> operator*(const big_int<bits> & b) const;
        // big_int<bits> operator%(const big_int<bits> & b);
        // big_int<bits> operator^(const int & b);
        big_int<bits> operator<<(const size_t & b) const;
        // big_int<bits> operator>>(const size_t & b);
        // big_int<bits> power_mod(const big_int<bits> & base, const int & exponent, const big_int<bits> & modulus);

        bool read(size_t place) const;
        void write(size_t place, bool value);

        big_int(){
            if(number == nullptr) throw std::runtime_error("Memory alloc failed.");
            for(size_t i = 0; i < limit; i++) number[i] = 0;
        }
};



template <const unsigned int bits>
bool big_int<bits>::operator==(const big_int<bits> & b) const{
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
bool big_int<bits>::operator!=(const big_int<bits> & b) const{
    return !(this->number == b.number);
}

template <const unsigned int bits>
bool big_int<bits>::operator<(const big_int<bits> & b) const{
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
bool big_int<bits>::operator<=(const big_int<bits> & b)const{
    return !(this->number > b.number);
}

template <const unsigned int bits>
bool big_int<bits>::operator>(const big_int<bits> & b) const{
    return b < this;
}

template <const unsigned int bits>
bool big_int<bits>::operator>=(const big_int<bits> & b) const{
    return b <= this;
}

template <const unsigned int bits>
big_int<bits> big_int<bits>::operator+(const big_int<bits> & b) const{
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
bool big_int<bits>::read(size_t place) const {
    size_t array_index = limit - std::floor(place / BITS_OF_UNSIGNED_INT) - 1;
    size_t bit_index = place % BITS_OF_UNSIGNED_INT;
    return (number[array_index] >> bit_index) & 1;
}

template <const unsigned int bits>
big_int<bits> big_int<bits>::operator<<(const size_t & b) const{
    big_int<bits> result;
    for(size_t digit = 0; digit < (this->limit * BITS_OF_UNSIGNED_INT) - b; digit++){
        result.write(digit + b + 1, this->read(digit));
    }
    return result;
}

template <const unsigned int bits>
big_int<bits> big_int<bits>::operator*(const big_int<bits> & b) const{
    big_int<bits> result;
    for(size_t i = 1; i <= b.limit * BITS_OF_UNSIGNED_INT; i++){
        if(this->read(i)){
            result += (b << (i - 1));
        }
    }
    return result;
}

int main(){
    big_int<64> a;
    a.number[a.limit - 1] = 0b01101101001100111001101011100100;
    a.number[a.limit - 2] = 0b01001100101011001001100101100101;
    big_int<64> b;
    b.number[b.limit - 1] = 0b01101101010010110101101000101100;
    b.number[b.limit - 2] = 0b10110110010100110001110010011010;
    // for(int i = 1; i <= 32; i++){
    //     a.read(i);
    // }
    // std::cout << std::endl;
    std::cout << std::bitset<BITS_OF_UNSIGNED_INT>(a.number[a.limit - 2]) << std::bitset<BITS_OF_UNSIGNED_INT>(a.number[a.limit - 1]) << std::endl;
    std::cout << std::bitset<BITS_OF_UNSIGNED_INT>(b.number[b.limit - 2]) << std::bitset<BITS_OF_UNSIGNED_INT>(b.number[b.limit - 1]) << std::endl;
    big_int<64> c;
    c = a * b;
    for(int i = 4; i >= 1; i--){
        std::cout << std::bitset<BITS_OF_UNSIGNED_INT>(c.number[c.limit - i]);
    }
    std::cout << std::endl;
}

// the right one: 110110100110111001100110010100111110001101110010000101101100011010000110110110000110100000110001011110000111101100011100110000
// my answer :1101101001101110011001100101001111100011011100100001011011000110100001101101100001101000001100010111100001111011000111001100
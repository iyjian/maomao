#include <iostream>
#include <cstdlib>
#include <string>
#include <climits>

template <const unsigned int bits_of_number>
class big_int{
    private:
        
    public:
        unsigned int data_limit = bits_of_number / (sizeof(unsigned int));
        unsigned int* data = (unsigned int*)malloc(bits_of_number / 8);
        void set_data(unsigned int num, unsigned int place);
        bool operator==(const big_int<bits_of_number> & b);
        bool operator!=(const big_int<bits_of_number> & b);
        bool operator<(const big_int<bits_of_number> & b);
        bool operator<=(const big_int<bits_of_number> & b);
        bool operator>(const big_int<bits_of_number> & b);
        bool operator>=(const big_int<bits_of_number> & b);
        big_int<bits_of_number> operator+(const big_int<bits_of_number> & b);
        // big_int<bits_of_number> operator-(const big_int<bits_of_number> & b);
        // big_int<bits_of_number> operator*(const big_int<bits_of_number> & b);
        // big_int<bits_of_number> operator/(const big_int<bits_of_number> & b);
        // big_int<bits_of_number> operator%(const big_int<bits_of_number> & b);
        // big_int<bits_of_number> operator^(const big_int<bits_of_number> & b);
        // big_int<bits_of_number> operator<<(const big_int<bits_of_number> & b);
        // big_int<bits_of_number> operator>>(const big_int<bits_of_number> & b);
        // big_int<bits_of_number> power_mod(const big_int<bits_of_number> & base, const big_int<bits_of_number> & exponent, const big_int<bits_of_number> & modulus);
        void __delete__(){
            free(data);
            data = nullptr;
            data_limit = 0;
        }
        big_int(const big_int& other) : data_limit(other.data_limit) {
            data = (unsigned int*)malloc(data_limit * sizeof(unsigned int));
            memcpy(data, other.data, data_limit * sizeof(unsigned int));
        }
    
        ~big_int() {
            free(data);
            data = nullptr;
        }
};

template <const unsigned int bits_of_number>
void big_int<bits_of_number>::set_data(unsigned int num, unsigned int place){
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
        std::cerr << "Error: data limits do not match." << std::endl;
        exit(-1);
    }
    big_int<bits_of_number> result;
    bool carry = 0;
    unsigned long temp;
    for(int i = 0; i < this->data_limit; i++){
        temp = (unsigned long)this->data[i] + (unsigned long)b.data[i] + carry;
        if(temp > UINT_MAX){
            carry = 1;
            temp -= (UINT_MAX + 1);
        }
        else{
            carry = 0;
        }
        result.data[i] = (unsigned int)temp;
    }
    return result;
}

int main(){
    big_int<64> a;
    big_int<64> b;
    a.set_data(1, 0);
    b.set_data(2, 0);
    big_int<64> c = a + b;
    std::cout << "Result: " << c.data[0] << std::endl; // Should print 3
    a.__delete__();
    b.__delete__();
    c.__delete__();
    return 0;
}
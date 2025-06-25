#include <boost/random.hpp>
#include <boost/multiprecision/number.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <vector>
#include <iostream>
using int_2048 = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<2048, 2048, boost::multiprecision::unsigned_magnitude, boost::multiprecision::checked, void>>;

int_2048 rand_num(int bits) {
    boost::random::mt19937 rng(static_cast<unsigned int>(std::time(0)));
    boost::random::uniform_int_distribution<int_2048> dist(1, int_2048(1) << (bits - 1));
    return dist(rng) | 1;
}

int find_factor_of_2(int_2048 n){
    int result;
    int_2048 n1 = n;
    whlie((n1 % 2) == 0){
        n1 /= 2;
        result ++;
    }
    return result;
}


bool is_prime(int_2048 p){

    boost::random::mt19937 rng;
    rng.seed(static_cast<unsigned int>(std::time(0)));
    boost::random::uniform_int_distribution<int_2048> dist(2, p - 2);
    int_2048 n = dist(rng);
    
    if(boost::multiprecision::powm(n, (p - 1), p) != 1){
        return false;
    }
    
    int s = find_factor_of_2(p - 1);
    int_2048 k = powm(n, ((p - 1) >> s), p);
    
    for(int i = 0; i < s; i++){
        if(k == (p - 1)){
            return true;
        }
        else if(k == 1){
            break;
        }
        k = boost::multiprecision::powm(k, 2, p);
    }
    return false;

}



int_2048 rand_prime(int bits){
    int_2048 n;
    bool prime = false;
    
        
    while (prime == false){
        n = rand_num(bits);
        prime = is_prime(n);
    }

    return n;
}

int main(){

    std::cout << is_prime(32317006071311007300714876688669951960444102669715484032130345427524655138867890893197201411522913463688717960921898019494119559150490921095088152386448283120630877367300996091750197750389652106796057638384067568276792218642619756161838094338476170470581645852036305042887575891541065808607552399123930385521914333389668342420684974786564569494856176035326322058077805659331026192708460314150258592864177116725943603718461857357598351152301645904403697613233287231227125684710820209725157101726931323469678542580656697935045997268352998638215525166389647960133216351542012121464521608892876832962973571615625796648961) << std::endl;
    return 0;
}
#include <random>
#include <vector>
#include <iostream>
#include <algorithm>
using std::vector;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int p = 17;
int q = 19;

int n = p * q;

int phi_n = (p - 1) * (q - 1);

// int randE(){
//     std::random_device rd;
//     std::mt19937 gen(rd());
//     std::uniform_int_distribution<> distr(1, phi_n);
//     int e;
//     vector<int> list;
//     do{
//         e = distr(gen);
//         if (std::find(list.begin(), list.end(), e) != list.end()){
//             continue;   
//         }
//         list.push_back(e);
//     } 
//     while (gcd(phi_n, e) != 1);
//     return e;
// }

int e = 37;


__uint32_t computeD(){
    // ex + φ(n)y = 1
    // x is the wanted value
    // ed ≡ 1 (mod φ(n))
    uint32_t temp = 1;
    while(temp % e != 0){
        temp += phi_n;
    }
    return temp / e;

}

int d = computeD();
#include <cmath>

int main(){
    std::cout <<  "n :" << n << " e :" << e << " d :" << d << std::endl;
    int m = 5;
    int p = static_cast<int>(std::pow(m, e)) % n;
    int m2 = static_cast<int>(std::pow(p, d)) % n;
    std::cout <<  p << "  " << m << std::endl;
}




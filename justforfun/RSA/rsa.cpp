#include <random>
#include <vector>
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

int randE(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(1, phi_n);
    int e;
    vector<int> list;
    do{
        e = distr(gen);
        if (std::find(list.begin(), list.end(), e) != list.end()){
            continue;   
        }
        list.push_back(e);
    } 
    while (gcd(phi_n, e) != 1);
    return e;
}

int e = randE();

int computeD(){
    // ex + φ(n)y = 1
    // x is the wanted value

}



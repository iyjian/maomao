#include <iostream>
#include <random>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

int is_it_random(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(1, 100);
    int32_t sum;
    for (unsigned int i = 0; i < 65535; i++){
        sum += distr(gen);
    }
    return sum - (50.5 * 65536);
}

int is_it_really_random(){
    int64_t sum;
    for (unsigned int i = 0; i < 10000; i++){
        sum += is_it_random();
    }
    return sum;
}

int main(){
    cout << is_it_really_random() << endl;
}

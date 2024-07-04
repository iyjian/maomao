#include <iostream>
bool checkPerfectNumber(int num){
    if (num == 1){
        return false;
    }
    int upper_bound = num / 2;
    int factor_sum = 1;
    int factor_maybe = 2;
    int another_factor = 0;
    while(factor_maybe < upper_bound){
        if (num % factor_maybe == 0){
            factor_sum += factor_maybe;
            another_factor = num / factor_maybe;
                if(another_factor != factor_maybe){
                    factor_sum += another_factor;
                    upper_bound = another_factor;
                }
                else{
                    break;
                }
        }
        factor_maybe += 1;
    }
    return num == factor_sum;
}

int main(){
    cout << checkPerfectNumber(28) << endl;
}
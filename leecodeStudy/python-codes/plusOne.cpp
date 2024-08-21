#include <vector>
using std::vector;


vector<int> plusOne(vector<int>& digits){
    vector<int> digits2 = digits;
    unsigned int i = digits2.back() + 1;
    digits2.pop_back();
    digits2.push_back(i % 10);
    digits2[digits2.size() - 2] = i - (i % 10);
    return digits2;
}
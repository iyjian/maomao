#include <vector>
using std::vector;
#include <iostream>
// 27

vector<int> removeElement(vector<int>& nums, int val){
    vector<int> nums2 = nums;
    for(int i : nums){
        if(i != val){
            nums2.push_back(i);
        }
    }
    return nums2;
}

template<typename T>
void printArray(const std::vector<T>& arr, std::ostream& out = std::cout) {
    for (const auto& element : arr) {
        out << element << " ";
    }
    out << std::endl; // 打印换行符
}

int main(){
}


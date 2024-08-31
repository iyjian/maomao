#include <vector>
#include <list>
#include <chrono>
#include <iostream>

int main() {
    std::vector<int> vec{1, 2, 3, 4, 5, 6};
    std::list<int> lst{1, 2, 3, 3, 6, 6, 4, 5, 6};

    auto startVec = std::chrono::high_resolution_clock::now();
    // 遍历 vector
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        // 执行一些操作
    }
    auto endVec = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diffVec = endVec - startVec;

    auto startList = std::chrono::high_resolution_clock::now();
    // 遍历 list
    for (auto it = lst.begin(); it != lst.end(); ++it) {
        // 执行相同的操作
    }
    auto endList = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diffList = endList - startList;

    std::cout << "Vector traversal time: " << diffVec.count() << " s\n";
    std::cout << "List traversal time: " << diffList.count() << " s\n";

    return 0;
}
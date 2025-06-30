#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

int main() {
    using namespace boost::multiprecision;
    
    // 方法1：使用pow函数
    cpp_int result = powm(cpp_int(2), cpp_int(127), 3);
    std::cout << "2^127 = " << result << std::endl;
    
    // 方法2：使用左移运算符（仅适用于2的幂次）
    cpp_int result2 = cpp_int(1) << 127;
    std::cout << "2^127 = " << result2 << std::endl;
    
    return 0;
}
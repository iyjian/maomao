#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;

int main(){
    cpp_int a("6553765537655376553765537655372222222211133");
    cpp_int b("100000000000000000000000000000");
    cpp_int c("33333333333333333333333");
    boost::multiprecision::powm(b, a);
}

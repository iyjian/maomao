#include <vector>
#include <string>
using std::vector;
using std::string;

vector<int> strToInt(string str){
    vector<int> result;
    for (char i : str){
        result.push_back(static_cast<int>(i));
    }
    return result;
}

string intToStr(vector<int> intigers){
    string result;
    for (int i : intigers){
        result.push_back(static_cast<char>(i));
    }
    return result;
}
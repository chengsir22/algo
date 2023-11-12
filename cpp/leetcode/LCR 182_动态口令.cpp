//
// Created by 鲁红呈 on 2023/11/4.
//
#include <string>

using namespace std;

class Solution {
public:
    string dynamicPassword(string password, int target) {
        std::reverse(password.begin(), password.begin()+target);
        std::reverse(password.begin()+target, password.end());
        reverse(password.begin(),password.end());
        return password;
    }
};
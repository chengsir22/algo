//
// Created by 鲁红呈 on 2023/10/28.
//
#include <string>

using namespace std;

class Solution {
public:
    string pathEncryption(string path) {
        string str;
        for(int i=0;i<path.size();i++){
            path[i]=='.'?str+=" ":str+=path[i];
        }
        return str;
    }
};
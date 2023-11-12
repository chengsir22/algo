//
// Created by 鲁红呈 on 2023/10/22.
//
#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int j = s.size()-1;
        for(int i=0;i<j;i++){
            int tmp = s[i];
            s[i]=s[j];
            s[j]=tmp;
            j--;
        }
    }
};
//
// Created by 鲁红呈 on 2023/10/27.
//
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int res = 0;
        unordered_set<char> lookup;
        for(int l=0,r=0;r<n;r++){
            while(lookup.find(s[r])!=lookup.end()){
                lookup.erase(s[l]);
                l++;
            }
            res = max(res,r-l+1);
            lookup.insert(s[r]);
        }
        return res;
    }
};
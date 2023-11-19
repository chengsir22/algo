//
// Created by 鲁红呈 on 2023/11/14.
//
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> need, window;
        for(const char &c:p){
            need[c]++;
        }
        int left =0,right=0;
        int valid=0;
        vector<int> res;

        while(right<s.size()){
            char c=s[right];
            right++;
            if(need.count(c)){
                window[c]++;
                if(window[c]==need[c]) valid++;
            }
            printf("window (%d,%d) valid %d; ",left,right,valid);
            while(right-left>= p.size()){
                if(valid==need.size()) res.push_back(left);
                char d=s[left];
                left++;
                if(need.count(d)){
                    if(window[d]==need[d])valid--;
                    window[d]--;
                }
            }
        }
        return res;
    }
};
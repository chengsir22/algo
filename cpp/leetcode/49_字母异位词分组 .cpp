//
// Created by 鲁红呈 on 2023/9/28.
//
//
// Created by 鲁红呈 on 2023/9/23.
//
#include <iostream>
#include <vector>
#include <stack>
#include <array>
#include <algorithm>
#include <numeric>  // for accumulate
#include <functional>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> map;
        for (auto &str :strs) {
            string key = str;
            sort(key.begin(),key.end());
            map[key].push_back(str);
        }
        vector<vector<string >> ret;
        for(auto& item : map){
            ret.push_back(item.second);
        }
        return ret;
    }
};


int main(int, char **)
{
    Solution s;

}

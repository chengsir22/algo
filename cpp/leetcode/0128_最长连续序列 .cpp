//
// Created by 鲁红呈 on 2023/9/28.
//
#include <iostream>
#include <vector>
#include <stack>
#include <array>
#include <algorithm>
#include <numeric>  // for accumulate
#include <functional>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        unordered_set<int> set;
        for(const int & num:nums){
            set.insert(num);
        }

        int maxL=0;

        for(int num : set){
            if(!set.count(num-1)){
                int curL =1;
                while(set.count(++num)){
                    curL++;
                }
                maxL = max(maxL,curL);
            }
        }
        return maxL;
    }
};


int main(int, char **) {
    Solution s;

}

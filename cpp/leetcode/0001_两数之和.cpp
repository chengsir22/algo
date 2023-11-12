//
// Created by 鲁红呈 on 2023/9/23.
//
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            auto iter = map.find(target-nums[i]);
            if(iter!=map.end()) {
                return {iter->second, i};
            }
            map.insert(pair<int,int>{nums[i],i});
        }
        return {};
    }
};






int main(int, char **)
{
    vector<int> nums = {2,7,11,15};
    Solution s;
    for (auto item : s.twoSum(nums,9)) {
        cout << item << endl;
    }
}

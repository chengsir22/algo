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
    int minSubArrayLen(int target, vector<int> &nums) {
        int len = nums.size();
        int sum = 0, i = 0, res = INT_MAX;
        for (int j = 0; j < len; j++) {
            sum += nums[j];
            while (sum >= target) {
                res = min(res, j - i + 1);
                sum -= nums[i];
                i++;
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};


int main(int, char **) {
    Solution s;

}

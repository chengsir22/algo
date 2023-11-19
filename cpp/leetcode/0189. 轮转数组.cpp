//
// Created by 鲁红呈 on 2023/11/15.
//
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        int n = nums.size();
        vector<int> newArr(n);
        for (int i = 0; i < n; i++) {
            newArr[(i+k)%n]=nums[i];
        }
        nums.assign(newArr.begin(),newArr.end());
    }
};
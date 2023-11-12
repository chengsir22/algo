//
// Created by 鲁红呈 on 2023/10/1.
//
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        int len = nums.size();
        int j = 0;
        for (int i = 0; i < len; i++) {
            if (nums[i] != 0) {
                nums[j] = nums[i];
                j++;
            }
        }
        for (j; j < len; j++) {
            nums[j] = 0;
        }
    }
};
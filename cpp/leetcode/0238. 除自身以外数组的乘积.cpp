//
// Created by 鲁红呈 on 2023/11/15.
//
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int n = nums.size();
        vector<int> res(n);
        int k = 1;
        for (int i = 0; i < n; i++) {
            res[i] = k;
            k = k * nums[i];
        }
        k=1;
        for(int i=n-1;i>=0;i--){
            res[i]*=k;
            k*=nums[i];
        }
        return res;
    }
};

//
// Created by 鲁红呈 on 2023/9/29.
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
    vector<int> sortedSquares(vector<int>& nums) {
        int i =0,n = nums.size()-1;
        int k = nums.size()-1;
        vector<int> res(nums.size(), 0);
        while(i<=n){
            if(nums[i]*nums[i]>=nums[n]*nums[n]){
                res[k--] = nums[i]*nums[i];
                i++;
            }else{
                res[k--]=nums[n]*nums[n];;
                n--;
            }
        }
        return res;
    }
};


int main(int, char **) {
    Solution s;

}

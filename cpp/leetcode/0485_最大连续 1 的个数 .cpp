//
// Created by 鲁红呈 on 2023/10/1.
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
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxL=0;
        for(int i =0,j=-1;i<nums.size();i++){
            if(nums[i]==1){
                maxL=max(i-j,maxL);
            } else{
                j=i;
            }
        }
        return maxL;
    }
};


int main(int, char **) {
    Solution s;

}

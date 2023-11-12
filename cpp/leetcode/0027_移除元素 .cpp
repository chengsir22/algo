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

using namespace std;

class Solution {
public:
    // 双指针法
    int removeElement(vector<int>& nums, int val) {
        int n =nums.size()-1,i=0;
        while(i<=n){
            if(nums[i]==val){
                swap(nums[i],nums[n--]);
            }else {
                i++;
            }
        }
        return i;
    }
};


int main(int, char **)
{
    Solution s;

}

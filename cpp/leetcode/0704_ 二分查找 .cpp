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
    int search(vector<int>& nums, int target) {
        int l=-1,r=nums.size();
        while(l+1!=r){
            int mid = l+(r-l>>1);
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid]<target){
                l=mid;
            }else{
                r=mid;
            }
        }
        return -1;
    }
};


int main(int, char **) {
    Solution s;

}

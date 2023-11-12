//
// Created by 鲁红呈 on 2023/10/1.
//
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l =-1,r=nums.size();
        while(l+1!=r){
            int mid = l + (r-l>>1);
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]<target){
                l=mid;
            }else {
                r = mid;
            }
        }
        return l+1;
    }
};
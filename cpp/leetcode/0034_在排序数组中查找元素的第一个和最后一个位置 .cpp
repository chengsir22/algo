//
// Created by 鲁红呈 on 2023/10/1.
//
#include <vector>

using namespace  std;

//class Solution {
//public:
//    vector<int> searchRange(vector<int>& nums, int target) {
//        int l = -1, r=nums.size();
//        while(l+1!=r){
//            int mid = l +(r-l>>1);
//            if(nums[mid]<target){
//                l=mid;
//            }else{
//                r=mid;
//            }
//        }
//        if(r==nums.size()||nums[r]!=target){
//            return {-1,-1};
//        }else{
//            int i=r;
//            while(i<nums.size()){
//                if(nums[i]!=target){
//                    return {r,--i};
//                }
//                i++;
//            }
//            return {r,--i};
//        }
//    }
//};

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int leftBorder = getLeftBorder(nums, target);
        int rightBorder = getRightBorder(nums, target);
        if(leftBorder==nums.size()||rightBorder==-1){
            return {-1,-1};
        }else if(nums[leftBorder]!=target){
            return {-1,-1};
        }else {
            return {leftBorder,rightBorder};
        }
    }
    int getRightBorder(vector<int>& nums, int target){
        int l = -1, r = nums.size();
        while (l + 1 != r) {
            int mid = l + (r - l >> 1);
            if (nums[mid] <= target) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return l;
    }
    int getLeftBorder(vector<int>& nums, int target){
        int l = -1, r = nums.size();
        while (l + 1 != r) {
            int mid = l + (r - l >> 1);
            if (nums[mid] < target) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return r;
    }

};

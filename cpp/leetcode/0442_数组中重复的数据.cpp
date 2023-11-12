//
// Created by 鲁红呈 on 2023/10/26.
//
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> res{};
        if (n<=1){
            return res;
        }
        for(int i=0;i<n;i++){
            while(nums[i]!=nums[nums[i]-1]){
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        for (int i=0;i<n;i++){
            if(nums[i]-1!=i){
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};
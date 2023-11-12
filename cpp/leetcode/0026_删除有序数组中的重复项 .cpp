//
// Created by 鲁红呈 on 2023/10/1.
//
#include <vector>

using  namespace  std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        int j=0
                ;
        for(int i =0;i<len;i++){
            if(i==0||nums[i]!=nums[i-1]){
                nums[j]=nums[i];
                j++;
            }
        }
        return j;
    }
};
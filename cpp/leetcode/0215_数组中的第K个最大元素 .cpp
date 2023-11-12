//
// Created by 鲁红呈 on 2023/11/4.
//
#include <vector>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        return quickselect(nums,0,n-1,n-k);
    }
    int select_value(int a, int b, int c) {
        if (a > b) swap(a, b);
        if (a > c) swap(a, c);
        if (b > c) swap(b, c);
        return b;
    }
    int quickselect(vector<int>& q, int l, int r,int k)
    {
        if (l==r) return q[k];
        int i = l - 1, j = r + 1, x = select_value(q[l], q[r], q[l + r >> 1]);
        while(i<j){
            do i++; while(q[i]< x);
            do j--; while(q[j]>x);
            if(i<j) swap(q[i],q[j]);
        }
        if(k<=j){
            return quickselect(q,l,j,k);
        }else {
            return quickselect(q,j+1,r,k);
        }
    }
};


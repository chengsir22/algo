//
// Created by 鲁红呈 on 2023/10/3.
//
#include <algorithm>
#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    int select_value(int a, int b, int c) {
        if (a > b) swap(a, b);
        if (a > c) swap(a, c);
        if (b > c) swap(b, c);
        return b;
    }

    void quick_sort(vector<int> &nums, int l, int r) {
        if (l >= r)return;
        int i = l-1, j = r+1;
        int x = select_value(nums[l], nums[r], nums[(l + r) >> 1]);
        while (i < j) {
            while(nums[++i]<x);
            while(nums[--j]>x);
            if (i < j)swap(nums[i], nums[j]);
        }
        quick_sort(nums, l, j);
        quick_sort(nums, j+1, r);
    }


    vector<int> sortArray(vector<int> &nums) {
        int l = 0, r = nums.size() - 1;
        quick_sort(nums, l, r);
        return nums;
    }
};
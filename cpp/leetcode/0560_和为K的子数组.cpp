//
// Created by 鲁红呈 on 2023/11/14.
//

#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        int sum = 0, ans = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for (int &i: nums) {
            sum+=i;
            if(mp.find(sum-k)!=mp.end()) ans+=mp[sum-k];
            mp[sum]++;
        }
        return ans;
    }
};


class Solution1 {
public:
    int subarraySum(vector<int> &nums, int k) {
        int count = 0;
        for (int left = 0; left < nums.size(); left++) {
            int sum = 0;
            for (int right = left; right < nums.size(); right++) {
                sum += nums[right];
                if (sum == k) {
                    count++;
                }
            }
        }
        return count;
    }
};
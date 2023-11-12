//
// Created by 鲁红呈 on 2023/10/25.
//
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int,int> cnt;
        int ans=0;
        for(int left=0,right=0;right<n;right++){
            cnt[fruits[right]]++;
            while(cnt.size()>2){
                auto it = cnt.find(fruits[left]);
                --it->second;
                if(it->second==0){
                    cnt.erase(it);
                }
                left++;
            }
            ans = max(ans,right-left+1);
        }
        return ans;
    }
};
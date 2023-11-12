//
// Created by 鲁红呈 on 2023/10/18.
//

#include <queue>

using namespace std;

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> q(nums.begin(),nums.end());
        long long ans=0;
        for (int i=0;i<k;i++){
            int x = q.top();
            q.pop();
            ans+=x;
            q.push((x+2)/3); //向上取整
        }
        return ans;
    }
};
int main(int, char **) {
    Solution s;

}

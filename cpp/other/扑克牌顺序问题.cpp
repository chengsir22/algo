//
// Created by 鲁红呈 on 2023/11/16.
//
#include <vector>
#include <iostream>

using namespace std;

// https://www.jianshu.com/p/cb2be415824c?ivk_sa=1024320u

class Solution {
public:
    vector<int> test(vector<int> nums) {
        vector<int> res;
        for (auto num: nums) {
            if (res.size() > 1) {
                res.insert(res.begin(), res[res.size() - 1]);
                res.pop_back();
            }
            res.insert(res.begin(), num);
        }
        return res;
    }
};

int main() {
    auto s = new Solution;
    vector<int> res = s->test(vector{13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1});
    for (int i; i < res.size(); i++) {
        printf("%d ", res[i]);
    }
    return 0;
}
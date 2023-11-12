//
// Created by 鲁红呈 on 2023/9/28.
//
//

#include <iostream>
#include <vector>
#include <stack>
#include <array>
#include <algorithm>
#include <numeric>  // for accumulate
#include <functional>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int top = 0, bottom = n - 1, left = 0, right = n - 1;
        vector<vector<int>> res(n, vector<int>(n, 0));
        int k = 1, totoal = n * n;
        while (k <= totoal) {
            for (int i = left; i <= right; i++, k++) res[top][i] = k;
            top++;
            for (int i = top; i <= bottom; i++, k++) res[i][right] = k;
            right--;
            for (int i = right; i >= left; i--, k++) res[bottom][i] = k;
            bottom--;
            for (int i = bottom; i >= top; i--, k++)res[i][left] = k;
            left++;
        }
        return res;
    }
};


int main(int, char **) {
    Solution s;

}

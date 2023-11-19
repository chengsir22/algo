//
// Created by 鲁红呈 on 2023/11/14.
//
#include <vector>

using namespace std;


class Solution {
public:
    int trap(vector<int> &height) {
        int n = height.size();
        if (n <= 2) return 0;
        vector<int> maxLeft(n, 0);
        vector<int> maxRight(n, 0);

        maxLeft[0] = height[0];
        for (int i = 1; i < n; i++) {
            maxLeft[i] = max(height[i], maxLeft[i - 1]);
        }

        maxRight[n-1]=height[n-1];
        for(int i = n-2;i>=0;i--){
            maxRight[i]=max(height[i],maxRight[i+1]);
        }

        int sum=0;
        for(int i=1;i<n-1;i++){
            int count = min(maxLeft[i],maxRight[i])-height[i];
            if(count>0) sum+=count;
        }
        return sum;
    }
};


class Solution1 {
public:
    int trap(vector<int> &height) {
        int sum = 0;
        for (int i = 0; i < height.size(); i++) {
            if (i == 0 || i == height.size() - 1) continue;
            int rh = height[i];
            int lh = height[i];
            for (int r = i + 1; r < height.size(); r++) {
                if (rh < height[r]) rh = height[r];
            }
            for (int l = i - 1; l >= 0; l--) {
                if (lh < height[l]) lh = height[l];
            }
            int h = min(lh, rh) - height[i];
            if (h > 0) sum += h;
        }
        return sum;
    }
};



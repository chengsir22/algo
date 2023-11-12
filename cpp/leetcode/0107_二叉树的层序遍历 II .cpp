//
// Created by 鲁红呈 on 2023/10/24.
//

#include <vector>
#include <queue>


using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
public:
    void order(TreeNode* cur,vector<vector<int>>& res,int depth){
        if(!cur) return;
        if(res.size()==depth) res.push_back(vector<int>());
        res[depth].push_back(cur->val);
        order(cur->left,res,depth+1);
        order(cur->right,res,depth+1);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res{};
        int depth =0;
        order(root,res,depth);
        reverse(res.begin(),res.end());
        return res;
    }
};
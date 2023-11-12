//
// Created by 鲁红呈 on 2023/10/21.
//
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> vec;
        preorder(root,vec);
        return vec;
    }
    void preorder(TreeNode* cur,vector<int>& vec){
        if (!cur) return;
        vec.push_back(cur->val);
        preorder(cur->left,vec);
        preorder(cur->right,vec);
    }
};

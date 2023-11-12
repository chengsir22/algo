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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vec;
        inorder(root,vec);
        return vec;
    }
    void inorder(TreeNode* cur,vector<int>& vec){
        if (!cur) return;

        inorder(cur->left,vec);
        vec.push_back(cur->val);
        inorder(cur->right,vec);
    }
};

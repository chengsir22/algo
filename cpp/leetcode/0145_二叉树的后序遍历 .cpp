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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> vec;
        postorder(root,vec);
        return vec;
    }
    void postorder(TreeNode* cur,vector<int>& vec){
        if (!cur) return;
        postorder(cur->left,vec);
        postorder(cur->right,vec);
        vec.push_back(cur->val);
    }
};
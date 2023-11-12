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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> que;
        vector<int> res;
        if(!root) return res;
        que.push(root);
        while(!que.empty()){
            int n = que.size();
            for(int i=0;i<n;i++){
                TreeNode* cur = que.front();
                que.pop();
                if(n==i+1){
                    res.push_back(cur->val);
                }
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
            }
        }
        return res;
    }
};
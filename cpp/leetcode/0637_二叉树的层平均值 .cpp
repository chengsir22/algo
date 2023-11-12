//
// Created by 鲁红呈 on 2023/11/8.
//

#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<double> averageOfLevels(TreeNode *root) {
        vector<double> res;
        if (!root) return res;
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            double total = 0;
            for (int i = 0; i < size; i++) {
                TreeNode *node = que.front();
                que.pop();
                total += node->val;
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            res.push_back(total/size);
        }
        return res;
    }
};
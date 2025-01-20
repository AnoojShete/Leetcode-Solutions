/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        queue<pair<TreeNode*, bool>> q;
        q.push({root, false});
        int sum = 0;
        while(!q.empty()) {
            auto [cur, isLeft] = q.front(); q.pop();
            if(!cur->left && !cur->right && isLeft) sum += cur->val;
            if(cur->left) q.push({cur->left, true});
            if(cur->right) q.push({cur->right, false});
        }

        return sum;
    }
};
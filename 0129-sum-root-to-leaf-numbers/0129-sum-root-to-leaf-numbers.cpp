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
    int solve(TreeNode* root, long long val = 0) {
        if(root == nullptr) return 0;

        val = val*10+root->val;

        if(root->left == nullptr && root->right == nullptr){
            return val;
        }

        return (solve(root->left, val) +
        solve(root->right, val));
    }
    int sumNumbers(TreeNode* root) {
        return solve(root, 0);
    }
};
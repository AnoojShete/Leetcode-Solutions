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
    long long solve(TreeNode* root, int target) {
        if(root == nullptr) return 0;
        return (target == root->val) +
        solve(root->left, target - root->val) + 
        solve(root->right, target - root->val);
        
    }
    int pathSum(TreeNode* root, int target) {
        if(!root) return 0;
                
        return solve(root, target) + 
                pathSum(root->left, target) +
                pathSum(root->right, target);
    }
};
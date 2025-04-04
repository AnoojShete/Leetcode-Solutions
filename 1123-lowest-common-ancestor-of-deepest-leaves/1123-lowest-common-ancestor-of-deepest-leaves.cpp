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
    pair<TreeNode*, int> solve(TreeNode* root, int depth) {
        if(!root) return {nullptr, depth};
        pair<TreeNode*, int> leftDepth = solve(root->left, depth + 1);
        pair<TreeNode*, int> rightDepth = solve(root->right, depth + 1);
        if(leftDepth.second > rightDepth.second) return leftDepth;
        else if(leftDepth.second < rightDepth.second) return rightDepth;
        else return {root, leftDepth.second}; 
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return solve(root, 0).first;
    }
};
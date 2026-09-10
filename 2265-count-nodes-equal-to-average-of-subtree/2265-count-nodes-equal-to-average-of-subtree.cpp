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
    int ans = 0;
    pair<int, int> solve(TreeNode* root) {
        if(!root) return {0, 0};
        auto left = solve(root->left);
        auto right = solve(root->right);
        
        int count = left.second + right.second + 1;
        int sum = left.first + right.first + root->val;
        if(sum / count == root->val) ans++; 
        return {sum, count};
    }
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return ans;
    }
};
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
    int solve(TreeNode* root, int &count, int k) {
        if(!root) return -1;
        
        int left = solve(root->left, count, k);
        if(left != -1) return left;

        count++;
        if(count == k) return root->val;

        int right = solve(root->right, count, k);

        return right;
    }
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        return solve(root, count, k);
    }
};
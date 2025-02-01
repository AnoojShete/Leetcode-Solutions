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
private:
    int dia = 0;
public:
    int solve(TreeNode* root) {
        if(!root) return 0;
        int ld = solve(root->left);
        int rd = solve(root->right);
        dia = max(dia, ld + rd);

        return max(ld, rd) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        solve(root);
        return dia;
    }
};
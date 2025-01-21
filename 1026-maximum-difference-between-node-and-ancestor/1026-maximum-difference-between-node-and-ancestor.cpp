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
    int diff = 0;
    void solve(TreeNode* root, int mini, int maxi) {
        if(!root) return;

        diff = max(diff, max(abs(mini - root->val), abs(maxi - root->val)));

        mini = min(mini, root->val);
        maxi = max(maxi, root->val);

        solve(root->left, mini, maxi);
        solve(root->right, mini, maxi);
    }
    int maxAncestorDiff(TreeNode* root) {
        if(!root) return 0;

        solve(root, root->val, root->val);
        
        return diff;
    }
};
typedef vector<int> vi;

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
    void solve(TreeNode* root, vi &ans, int lvl) {
        if(root == nullptr) return;
        if(ans.size() == lvl) ans.push_back(root->val);
        solve(root->right, ans, lvl + 1);
        solve(root->left, ans, lvl + 1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vi ans;
        solve(root, ans, 0);

        return ans;
    }
};
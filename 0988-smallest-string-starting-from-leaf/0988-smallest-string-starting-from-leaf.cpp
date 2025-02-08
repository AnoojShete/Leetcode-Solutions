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
    void solve(TreeNode* root, string temp, string &ans) {
        if(!root) return;
        temp += 'a' + root->val;
        if(root->left == nullptr && root->right == nullptr) {
            reverse(temp.begin(), temp.end());
            if(ans.empty() || temp < ans)
                ans = temp;
        }
        solve(root->left, temp, ans);
        solve(root->right, temp, ans);
    }
    string smallestFromLeaf(TreeNode* root) {
        string ans;
        string temp = "";
        solve(root, temp, ans);

        return ans;
    }
};
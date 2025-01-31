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
    void solve(TreeNode* root, unordered_map<int, int> &mpp, int &maxi, vector<int> &ans) {
        if(!root) return;

        solve(root->left, mpp, maxi, ans);

        int count = mpp[root->val]++;
        if(count > maxi) {
            maxi = count;
            ans = {root->val};
        }
        else if(count == maxi) ans.push_back(root->val);

        solve(root->right, mpp, maxi, ans);
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> mpp;
        vector<int> ans;
        int maxi = 0;

        solve(root, mpp, maxi, ans);

        return ans;
    }
};
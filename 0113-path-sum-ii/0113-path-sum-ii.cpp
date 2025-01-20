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
    void solve(TreeNode* root, int k, vector<int> &path, vector<vector<int>> &paths) {
        if(!root) return;

        path.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr) {
            if(root->val == k) paths.push_back(path);
        }

        solve(root->left, k - root->val, path, paths);
        solve(root->right, k - root->val, path, paths);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> pathSums;
        vector<int> path;
        solve(root, targetSum, path, pathSums);
        return pathSums;
    }
};
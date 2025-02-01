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
    void getInorder(TreeNode* root, vector<int> &in) {
        if(!root) return;
        getInorder(root->left, in);
        in.push_back(root->val);
        getInorder(root->right, in);
    }
    void solve(TreeNode* root, vector<int> &inorder, int &i, int n) {
        if(!root) return;
        solve(root->left, inorder, i, n);
        root->val = inorder[i++];
        solve(root->right, inorder, i, n);
    }
    void recoverTree(TreeNode* root) {
        vector<int> inorder;
        getInorder(root, inorder);
        sort(inorder.begin(), inorder.end());
        int i = 0;
        solve(root, inorder, i, inorder.size()-1);
    }
};
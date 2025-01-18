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
    TreeNode* createUniqueBinaryTree(unordered_map<int,int> &mp, vector<int>& pre, 
                     int &preIndex, int s, int e) {
        if (s>e) return nullptr;
        TreeNode* root = new TreeNode(pre[preIndex]);
        preIndex++;
        int index = mp[pre[preIndex-1]];
        root->left = createUniqueBinaryTree(mp, pre, preIndex, s, index-1);
        root->right = createUniqueBinaryTree(mp, pre, preIndex, index+1, e);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex = 0;
        int n = preorder.size();
        unordered_map<int,int> mp;
        for (int i=0; i<n; i++) {
            mp[inorder[i]] = i;
        }
        TreeNode* root = createUniqueBinaryTree(mp, preorder, preIndex, 0, n-1);
        return root;
    }
};
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
    TreeNode* createUniqueBinaryTree(vector<int>& inorder, vector<int>& postorder, int inStrt, 
                int inEnd, int& pIndex, unordered_map<int, int>& mp) {

        if (inStrt > inEnd)
            return NULL;

        int curr = postorder[pIndex];
        TreeNode* node = new TreeNode(curr); 
        pIndex--;

        if (inStrt == inEnd)
            return node;

        int iIndex = mp[curr];

        node->right = createUniqueBinaryTree(inorder, postorder, iIndex + 1, inEnd, pIndex, mp);  
        node->left = createUniqueBinaryTree(inorder, postorder, inStrt, iIndex - 1, pIndex, mp);  

        return node;  
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& post) {
        int len = inorder.size();  
        unordered_map<int, int> mp;
        for (int i = 0; i < len; i++)
            mp[inorder[i]] = i;
        int postIndex = len - 1;
        
        return createUniqueBinaryTree(inorder, post, 0, len - 1, postIndex, mp);
    }
};
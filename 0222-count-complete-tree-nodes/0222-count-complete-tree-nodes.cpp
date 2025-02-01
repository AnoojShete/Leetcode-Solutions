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
    int rightHeight(TreeNode* node) {
        int h;
        while(node) {
            node = node->right;
            h++;
        }
        return h;
    }
    int leftHeight(TreeNode* node) {
        int h;
        while(node) {
            node = node->left;
            h++;
        }
        return h;
    }
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;

        int lh = leftHeight(root);
        int rh = rightHeight(root);

        if(lh == rh) {
            // Then its a full binary tree
            return (1<<lh) - 1;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
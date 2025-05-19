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
    void solve(TreeNode* root, int &mini, int &second_mini) {
        if(root == nullptr) return;

        if(root->val < mini) {
            second_mini = mini;
            mini = root->val;
        }
        else if(root->val < second_mini && root->val != mini) {
            second_mini = root->val;
        }

        solve(root->left, mini, second_mini);
        solve(root->right, mini, second_mini);
    }
    int findSecondMinimumValue(TreeNode* root) {
        int mini = INT_MAX;
        int second_mini = INT_MAX;
        solve(root, mini, second_mini);

        return second_mini == INT_MAX ? -1 : second_mini;
    }
};
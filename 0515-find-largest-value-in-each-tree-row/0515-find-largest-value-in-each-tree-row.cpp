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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            int maxi = INT_MIN; 
            for(int i = 0; i < n; i++) {
                auto node = q.front(); q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                if(node->val > maxi) maxi = node->val;
            }
            ans.push_back(maxi);
        }

        return ans;
    }
};
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        stack<vector<int>> st;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            vector<int> level(n);
            for(int i = 0; i < n; i++) {
                TreeNode* node = q.front(); q.pop();
                level[i] = node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            st.push(level);
        }
        while(!st.empty()) {
            vector<int> v = st.top(); st.pop();
            ans.push_back(v);
        }
        
        return ans;
    }
};
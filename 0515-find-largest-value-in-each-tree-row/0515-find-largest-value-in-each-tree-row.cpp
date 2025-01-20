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
        map<int, set<int, greater<int>>> mpp;
        int level = 0;
        queue<TreeNode*> q;
        q.push(root);
        mpp[0].insert(root->val);

        while(!q.empty()) {
            int n = q.size();
            for(int i = 0; i < n; i++) {
                auto node = q.front(); q.pop();
                if(node)
                    mpp[level].insert(node->val);

                if(node->left) {
                    q.push(node->left);
                }
                if(node->right) {
                    q.push(node->right);
                } 
            }
            level++;
        }
        for(auto p : mpp) {
            ans.push_back(*p.second.begin());
        }

        return ans;
    }
};
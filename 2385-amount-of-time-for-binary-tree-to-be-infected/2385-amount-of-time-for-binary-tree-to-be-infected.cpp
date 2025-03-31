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
    unordered_map<int, vector<int>> convertIntoGraph(TreeNode* root) {
        unordered_map<int, vector<int>> adj;
        queue<pair<TreeNode*, int>> q;
        q.push({root, -1});
        
        while(!q.empty()) {
            auto [node, parent] = q.front(); q.pop();
            if(parent != -1){
                adj[parent].push_back(node->val);
                adj[node->val].push_back(parent);
            }
            if(node->left)  q.push({node->left,node->val});
            if(node->right) q.push({node->right,node->val});
        }

        return adj;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> adj = convertIntoGraph(root);

        queue<int> q;
        unordered_map<int, bool> vis;
        q.push(start);
        vis[start] = true;
        
        int d = 0;
        while(!q.empty()) {
            int n = q.size();
            while(n--) {
                auto node = q.front(); q.pop();
                for(auto it : adj[node]) {
                    if(!vis[it]) {
                        q.push(it);
                        vis[it] = true;
                    }
                }
            }
            d++;
        }

        return d - 1;
    }
};
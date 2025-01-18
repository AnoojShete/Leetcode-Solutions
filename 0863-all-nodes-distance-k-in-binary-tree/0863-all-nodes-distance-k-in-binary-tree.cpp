/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void getParentTrack(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent_track) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if(node->left) {
                parent_track[node->left] = node;
                q.push(node->left);
            }
            if(node->right) {
                parent_track[node->right] = node;
                q.push(node->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // Step-1 : To traverse in upward we need parent track i.e. BFS and hashMap
        unordered_map<TreeNode*, TreeNode*> parent_track;
        getParentTrack(root, parent_track);

        // Step-2 : Make a visited ds
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;

        int dist = 0;

        // Step-3 : Radially move outwards(upwards and downwards simul)
        while(!q.empty()) {
            int size = q.size();
            if(dist == k) break;
            dist++;
            for(int i=0; i<size; i++) {
                TreeNode* node = q.front(); q.pop();
                if(node->left && !visited[node->left]) {
                    q.push(node->left);
                    visited[node->left] = true;
                }
                if(node->right && !visited[node->right]) {
                    q.push(node->right);
                    visited[node->right] = true;
                }
                if(parent_track[node] && !visited[parent_track[node]]) {
                    q.push(parent_track[node]);
                    visited[parent_track[node]] = true;
                }
            }
        }
        vector<int> ans;
        while(!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            ans.push_back(node->val);
        }
        return ans;
    }
};
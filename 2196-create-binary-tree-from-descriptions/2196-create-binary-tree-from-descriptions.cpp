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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mpp;
        unordered_set<int> st;
        for(auto desc : descriptions) {
            int par = desc[0], child = desc[1], isLeft = desc[2];
            if(!mpp.count(par)) {
                mpp[par] = new TreeNode(par);
            }
            if(!mpp.count(child)) {
                mpp[child] = new TreeNode(child);
            }
            if(isLeft) {
                mpp[par]->left = mpp[child];
            } else {
                mpp[par]->right = mpp[child];
            }
            st.insert(child);
        }
        for(auto &[val, node] : mpp) {
            if(st.find(val) == st.end()) return node;
        }
        return nullptr;
    }
};
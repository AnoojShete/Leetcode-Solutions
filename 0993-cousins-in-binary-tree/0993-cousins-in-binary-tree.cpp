class Solution {
public:
    int xlevel = -1, ylevel = -1;
    TreeNode *xt, *yt;
    void dfs(TreeNode* root, TreeNode* parent, int level, int x, int y) {
        if(!root) return;
        if(root->val == x) xlevel = level, xt = parent;
        if(root->val == y) ylevel = level, yt = parent;
        dfs(root->left, root, level + 1, x, y);
        dfs(root->right, root, level + 1, x, y);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, root, 0, x, y);
        return xlevel == ylevel && xt != yt;
    }
};
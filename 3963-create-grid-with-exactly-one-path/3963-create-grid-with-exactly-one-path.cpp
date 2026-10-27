class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans;
        string block = ".";
        for(int i = 0; i < n-1; ++i) {
            block.push_back('#');
        }
        for(int i = 0; i < m-1; ++i) {
            ans.push_back(block);
        }
        block.clear();
        for(int i = 0; i < n; ++i) {
            block.push_back('.');
        }
        ans.push_back(block);
        return ans;
    }
};
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> ans;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                int curr = mat[i][j];
                int left = (j == 0) ? -1 : mat[i][j - 1];
                int right = (j == m - 1) ? -1 : mat[i][j + 1];
                int top = (i == n - 1) ? -1 : mat[i + 1][j];
                int down = (i == 0) ? -1 : mat[i - 1][j];
                if(curr > top && curr > left && curr > right && curr > down) {
                    return {i, j};
                }
                cout << curr << endl;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> prefixSum(m+1, vector<int>(n+1));
        for(int i = 0; i < m; ++i) prefixSum[i][0] = 0;
        for(int i = 0; i < n; ++i) prefixSum[0][i] = 0;
        int count = 0;
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                prefixSum[i][j] = grid[i-1][j-1] + prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1];
                if(prefixSum[i][j] <= k) count++;
            }
        }
        return count;
    }
};
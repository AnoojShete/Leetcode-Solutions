class Solution {
public:
    int dp[71][71][71];
    int solve(int row1, int col1, int col2, vector<vector<int>> &grid) {
        int row2 = row1;
        int m = grid.size(), n = grid[0].size();
        if(row1 < 0 || col1 < 0 || row1 >= m || col1 >= n
        || row2 < 0 || col2 < 0 || row2 >= m || col2 >= n) return INT_MIN;
        if(row1 == m-1 && row2 == m-1) {
            if(col1 == col2) return grid[row1][col1];
            return grid[row1][col1] + grid[row2][col2];
        }
        if(dp[row1][col1][col2] != -1) return dp[row1][col1][col2];
        int delta[3][2] = {{1, -1}, {1, 0}, {1, 1}};
        int ans = INT_MIN;
        for(auto d1 : delta) {
            for(auto d2 : delta) {
                int nrow1 = row1 + d1[0];
                int ncol1 = col1 + d1[1];
                int nrow2 = row2 + d2[0];
                int ncol2 = col2 + d2[1];
                ans = max(ans, solve(nrow1, ncol1, ncol2, grid));
            }
        }
        ans += grid[row1][col1];
        if(row1 != row2 || col1 != col2) ans += grid[row2][col2];
        return dp[row1][col1][col2] = ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof dp);
        return max(0, solve(0, 0, grid[0].size()-1, grid));
    }
};
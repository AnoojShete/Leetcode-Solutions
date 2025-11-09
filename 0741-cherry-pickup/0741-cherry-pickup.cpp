class Solution {
public:
    int dp[51][51][51];
    int solve(int row1, int col1, int row2, int n, vector<vector<int>> &grid) {
        int col2 = row1 + col1 - row2;
        if(row1 >= n || col1 >= n || row2 >= n || col2 >= n
        || grid[row1][col1] == -1 || grid[row2][col2] == -1) return INT_MIN;
        if(row1 == n-1 && col1 == n-1 && row2 == n-1) return grid[row1][col1];
        if(dp[row1][col1][row2] != -1) return dp[row1][col1][row2];
        int delta[2][2] = {{1, 0}, {0, 1}};
        int ans = INT_MIN;
        for(auto d1 : delta) {
            for(auto d2 : delta) {
                int nrow1 = row1 + d1[0];
                int ncol1 = col1 + d1[1];
                int nrow2 = row2 + d2[0];
                ans = max(ans, solve(nrow1, ncol1, nrow2, n, grid));
            }
        }
        ans += grid[row1][col1];
        if(row1 != row2) ans += grid[row2][col2];
        return dp[row1][col1][row2] = ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        memset(dp, -1, sizeof dp);
        return max(0, solve(0, 0, 0, n, grid));
    }
};
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>> (n, vector<int> (1 << 10, -1)));
        function<int(int, int, int)> solve = [&](int x, int y, int xr) -> int {
            if(x > m-1 || y > n-1) return INT_MAX;
            if(x == m-1 && y == n-1) {
                return xr ^ grid[x][y];
            }
            if(dp[x][y][xr] != -1) return dp[x][y][xr];
            int ans = 0;
            ans = min(solve(x + 1, y, xr ^ grid[x][y]), solve(x, y + 1, xr ^ grid[x][y]));
            return dp[x][y][xr] = ans;
        };
        return solve(0, 0, 0);
    }
};
class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        const int mod = 1e9 + 7;
        vector<vector<vector<int>>> dp(m, vector<vector<int>> (n, vector<int> (2, -1)));
        auto dfs = [&](auto &&dfs, int x, int y, bool flag) {
            if(x >= m || y >= n) return 0;
            if(x == m-1 && y == n-1) return 1;
            if(dp[x][y][flag] != -1) return dp[x][y][flag];
            int count = 0;
            if(!grid[x][y]) count = (dfs(dfs, x + 1, y, true) + dfs(dfs, x, y + 1, false)) % mod;
            else {
                if(flag) {
                    count = (count + dfs(dfs, x, y + 1, false)) % mod;
                } else {
                    count = (count + dfs(dfs, x + 1, y, true)) % mod;
                }
            }
            return dp[x][y][flag] = count;
        };
        return dfs(dfs, 0, 0, false) % mod;
    }
};
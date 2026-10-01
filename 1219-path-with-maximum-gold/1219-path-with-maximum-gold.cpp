class Solution {
public:
    bool inBounds(int row, int col, int m, int n) {
        return row >= 0 && col >= 0 && row < m && col < n;
    }
    int solve(int row, int col, vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        if(!inBounds(row, col, m, n)) return 0;
        if(grid[row][col] == 0) return 0;
        
        int gold = grid[row][col];
        grid[row][col] = 0;
        int ans = max({
            solve(row + 1, col, grid),
            solve(row - 1, col, grid),
            solve(row, col + 1, grid),
            solve(row, col - 1, grid)
        });
        grid[row][col] = gold;
        return gold + ans;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; j++) {
                ans = max(ans, solve(i, j, grid));
            }
        }
        return ans;
    }
};
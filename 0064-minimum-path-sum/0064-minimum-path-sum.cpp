class Solution {
public:
    int memo[201][201];
    int solve(int row, int col, vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        if(row == m || col == n) return INT_MAX;
        if(row == m-1 && col == n-1) return grid[row][col];
        if(memo[row][col] != -1) return memo[row][col];
        
        return memo[row][col] = grid[row][col] + min(solve(row + 1, col, grid), solve(row, col + 1, grid));
    }
    int minPathSum(vector<vector<int>>& grid) {
        memset(memo, -1, sizeof memo);
        return solve(0, 0, grid);
    }
};
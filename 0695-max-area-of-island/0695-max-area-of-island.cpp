class Solution {
public:
    bool inBounds(int row, int col, int n, int m) {
        return row >= 0 && col >= 0 && row < n && col < m;
    }
    int dfs(int row, int col, vector<vector<int>> &grid) {
        grid[row][col] = 0;
        int delta[] = {-1, 0, 1, 0, -1};
        int count = 1;
        for(int i = 0; i < 4; ++i) {
            int nrow = row + delta[i];
            int ncol = col + delta[i + 1];
            if(inBounds(nrow, ncol, grid.size(), grid[0].size()) && grid[nrow][ncol] == 1) {
                count += dfs(nrow, ncol, grid);
            }
        }
        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxArea = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(grid[i][j] == 1) {
                    maxArea = max(maxArea, dfs(i, j, grid));
                }
            }
        }

        return maxArea;
    }
};
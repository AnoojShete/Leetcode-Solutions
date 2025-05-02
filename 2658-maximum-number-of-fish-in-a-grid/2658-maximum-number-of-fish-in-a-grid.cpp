class Solution {
public:
    bool inBounds(int row, int col, int n, int m) {
        return row >= 0 && col >= 0 && row < n && col < m;
    }
    void dfs(int row, int col, vector<vector<int>> &grid, int &fish) {
        grid[row][col] = 0;
        int delta[] = {-1, 0, 1, 0, -1};
        for(int i = 0; i < 4; ++i) {
            int nrow = row + delta[i];
            int ncol = col + delta[i + 1];
            if(inBounds(nrow, ncol, grid.size(), grid[0].size()) && grid[nrow][ncol] > 0) {
                fish += grid[nrow][ncol];
                dfs(nrow, ncol, grid, fish);
            }
        }
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int maxFish = 0;
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j] > 0) {
                    int fish = grid[i][j];
                    dfs(i, j, grid, fish);
                    maxFish = max(maxFish, fish);
                }
            }
        }

        return maxFish;
    }
};
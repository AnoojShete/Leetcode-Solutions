class Solution {
public:
    void dfs(int row, int col, vector<vector<char>> &grid,
            int delRow[], int delCol[], int n, int m) {
        for(int i = 0; i < 4; ++i) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if(nrow >= 0 && ncol >= 0 && nrow < n &&
            ncol < m && grid[nrow][ncol] != '0') {
                grid[nrow][ncol] = '0';
                dfs(nrow, ncol, grid, delRow, delCol, n, m);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int count = 0;
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(grid[i][j] == '1') {
                    dfs(i, j, grid, delRow, delCol, n, m);
                    count++;
                }
            }
        }

        return count;
    }
};
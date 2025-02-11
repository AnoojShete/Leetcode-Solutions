class Solution {
public:
    int count = 0, empty = 1, start_r = 0, start_c = 0;

    void solve(vector<vector<int>> &grid, int r, int c) {
        if(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == -1) {
            return;
        }
        if(grid[r][c] == 2) {
            if(empty == 0) count++;
            return;
        }

        grid[r][c] = -1;
        empty--;

        solve(grid, r + 1, c);
        solve(grid, r - 1, c);
        solve(grid, r, c + 1);
        solve(grid, r, c - 1);

        // backtrack
        grid[r][c] = 0;
        empty++;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 0) empty++;
                else if(grid[i][j] == 1) {
                    start_r = i;
                    start_c = j;
                }
            }
        }
        
        solve(grid, start_r, start_c);

        return count;
    }
};
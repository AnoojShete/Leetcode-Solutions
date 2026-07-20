class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        k %= (m*n);
        while(k--) {
            int prev = grid[m-1][n-1];
            for(int i = 0; i < m; ++i) {
                for(int j = 0; j < n; ++j) {
                    int temp = grid[i][j];
                    grid[i][j] = prev;
                    prev = temp;
                }
            }
        }
        return grid;
    }
};
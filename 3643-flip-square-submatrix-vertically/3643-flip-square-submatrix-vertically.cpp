class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int n = grid.size();
        for(int i = 0; i < k/2; ++i) {
            for(int j = 0; j < k; ++j) {
                swap(grid[i+x][j+y], grid[k-1-i+x][j+y]);
            }
        }
        return grid;
    }
};
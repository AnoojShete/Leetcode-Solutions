class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0] || grid[n-1][m-1]) return 0;
        int t[101][101];
        t[0][0] = grid[0][0] ? 0 : 1;
        for(int i = 1; i < m; ++i) t[0][i] = grid[0][i] ? 0 : t[0][i-1];
        for(int i = 1; i < n; ++i) t[i][0] = grid[i][0] ? 0 : t[i-1][0];
        for(int i = 1; i < n; ++i) {
            for(int j = 1; j < m; ++j) {
                if(!grid[i][j]) {
                    t[i][j] = t[i-1][j] + t[i][j-1];
                }
                else t[i][j] = 0;
            }
        }
        return t[n-1][m-1];
    }
};
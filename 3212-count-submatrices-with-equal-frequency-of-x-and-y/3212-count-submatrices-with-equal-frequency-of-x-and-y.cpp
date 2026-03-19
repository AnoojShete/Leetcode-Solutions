class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> sumX(n, 0);
        vector<int> sumY(n, 0);
        int ans = 0;
        for(int i = 0; i < m; i++) {
            int x = 0, y = 0;
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 'X') x++;
                else if(grid[i][j] == 'Y') y++;
                sumX[j] += x, sumY[j] += y;
                if(sumX[j] && sumX[j] == sumY[j]) ans++;
            }
        }
        return ans;
    }
};
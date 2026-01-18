class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> row(m, vector<int>(n));
        vector<vector<int>> col(m, vector<int>(n));
        vector<vector<int>> diag1(m, vector<int>(n));
        vector<vector<int>> diag2(m, vector<int>(n));
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                row[i][j] = grid[i][j] +(j > 0 ? row[i][j-1] : 0);
                col[i][j] = grid[i][j] +(i > 0 ? col[i-1][j] : 0);
                diag1[i][j] = grid[i][j] +(i > 0 && j > 0 ? diag1[i-1][j-1] : 0);
                diag2[i][j] = grid[i][j] +(i > 0 && j + 1 < n ? diag2[i-1][j+1] : 0);
            }
        }
        int sz = min(m, n);
        for(int k = sz; k >= 2; --k) {
            for(int i = 0; i <= m-k; ++i) {
                for(int j = 0; j <= n-k; ++j) {
                    int x = row[i][j+k-1] -(j > 0 ? row[i][j-1] : 0);
                    bool flag = true;

                    for(int r = i; r < i + k && flag; ++r) {
                        int sum = row[r][j+k-1] - (j > 0 ? row[r][j-1] : 0);
                        if(sum != x) flag = false;
                    }

                    for(int c = j; c < j + k && flag; c++) {
                        int sum = col[i+k-1][c] - (i > 0 ? col[i-1][c] : 0);
                        if(sum != x) flag = false;
                    }

                    int d1 = diag1[i+k-1][j+k-1] - (i > 0 && j > 0 ? diag1[i-1][j-1] : 0);
                    int d2 = diag2[i+k-1][j] - (i > 0 && j + k < n ? diag2[i-1][j+k] : 0);

                    if(flag && d1 ==x && d2 ==x)
                        return k;
                }
            }
        }
        return 1;
    }
};
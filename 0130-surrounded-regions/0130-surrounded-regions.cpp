class Solution {
public:
    void dfs(int row, int col, vector<vector<char>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        mat[row][col] = '#';
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        for(int i = 0; i < 4; i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if(nrow >= 0 && ncol >= 0 && nrow < n && 
            ncol < m && mat[nrow][ncol] == 'O') {
                dfs(nrow, ncol, mat);
            }
        }
    }
    void solve(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                    if(mat[i][j] == 'O') {
                        dfs(i, j, mat);
                    }
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 'O') mat[i][j] = 'X';
                else if(mat[i][j] == '#') mat[i][j] = 'O';
            }
        }
    }
};
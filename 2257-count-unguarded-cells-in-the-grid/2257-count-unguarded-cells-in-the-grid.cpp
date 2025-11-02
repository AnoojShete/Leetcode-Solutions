class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for(auto &w : walls) {
            int row = w[0], col = w[1];
            vis[row][col] = -1;
        }
        for(auto &g : guards) {
            int row = g[0], col = g[1];
            vis[row][col] = 1;
            int tempRow = row;
            while(tempRow >= 0 && vis[tempRow][col] != -1) {
                vis[tempRow][col] = 1;
                tempRow--;
            }
            tempRow = row;
            while(tempRow < m && vis[tempRow][col] != -1) {
                vis[tempRow][col] = 1;
                tempRow++;
            }
            int tempCol = col;
            while(tempCol >= 0 && vis[row][tempCol] != -1) {
                vis[row][tempCol] = 1;
                tempCol--;
            }
            tempCol = col;
            while(tempCol < n && vis[row][tempCol] != -1) {
                vis[row][tempCol] = 1;
                tempCol++;
            }
        }
        int count = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(vis[i][j] == 0) count++;
            }
        }
        return count;
    }
};
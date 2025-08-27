class Solution {
public:
    const vector<pair<int, int>> dirs = {{-1, 1}, {1, 1}, {1, -1}, {-1, -1}};
    int memo[501][501][4][2];
    bool inBounds(int row, int col, int m, int n) {
        return row >= 0 && col >= 0 && row < m && col < n;
    }

    int solve(int row, int col, bool isTurn, int dir, 
    int val, vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        if(!inBounds(row, col, m, n) || grid[row][col] != val) return 0;
        if(memo[row][col][dir][isTurn] != -1) return memo[row][col][dir][isTurn];
        int nextVal = val == 2 ? 0 : 2;
        int count = 1;
        int nrow = row + dirs[dir].first, ncol = col + dirs[dir].second;
        count += solve(nrow, ncol, isTurn, dir, nextVal, grid);
        if(!isTurn) {
            int newDir = (dir + 1) % 4;
            int nrow = row + dirs[newDir].first, ncol = col + dirs[newDir].second;
            count = max(count, 1 + solve(nrow, ncol, true, newDir, nextVal, grid));
        }
        return memo[row][col][dir][isTurn] = count;
    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        // edge case
        memset(memo, -1, sizeof memo);
        int ans = 1;
        for(int row = 0; row < m; ++row) {
            for(int col = 0; col < n; ++col) {
                if(grid[row][col] == 1) {
                    for(int i = 0; i < 4; ++i) {
                        int nrow = row + dirs[i].first;
                        int ncol = col + dirs[i].second;
                        if(inBounds(nrow, ncol, m, n) && grid[nrow][ncol] == 2) {
                            ans = max(ans, 1 + solve(nrow, ncol, false, i, 2, grid));
                        }
                    }
                }
            }
        }
        return ans;
    }
};
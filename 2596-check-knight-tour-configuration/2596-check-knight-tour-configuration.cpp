class Solution {
public:
    bool inBounds(int x, int y, int n) {
        return x >= 0 && y >= 0 && x < n && y < n;
    }
    bool solve(int val, int x, int y, vector<vector<int>> &grid) {
        if(val == grid.size() * grid.size() - 1) return true;
        grid[x][y] = -1;
        int delta[8][2] = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-1, -2}, {1, -2}};
        for(int i = 0; i < 8; ++i) {
            int dx = x + delta[i][0];
            int dy = y + delta[i][1];

            if(inBounds(dx, dy, grid.size()) && grid[dx][dy] == val + 1) {
                if(solve(val + 1, dx, dy, grid)) return true;
            }
        }
        grid[x][y] = val;

        return false;
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        if(grid[0][0] != 0) return false;
        return solve(0, 0, 0, grid);
    }
};
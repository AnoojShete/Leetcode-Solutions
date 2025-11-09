class Solution {
public:
    vector<vector<vector<int>>> memo;
    int solve(int row, int col, vector<vector<int>> &grid, int k) {
        int m = grid.size(), n = grid[0].size();
        if (row >= m || col >= n || k < 0) return INT_MIN;

        int cost = (grid[row][col] == 0 ? 0 : 1);
        int val = grid[row][col];

        if (row == m - 1 && col == n - 1)
            return (k - cost < 0) ? INT_MIN : val;

        if (memo[row][col][k] != -1) return memo[row][col][k];

        int score = INT_MIN;
        int delta[2][2] = {{1, 0}, {0, 1}};
        for (auto &d : delta) {
            int nrow = row + d[0];
            int ncol = col + d[1];
            score = max(score, solve(nrow, ncol, grid, k - cost));
        }

        if (score == INT_MIN) return memo[row][col][k] = INT_MIN;
        return memo[row][col][k] = score + val;
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        memo.assign(m, vector<vector<int>>(n, vector<int>(k + 1, -1)));
        int ans = solve(0, 0, grid, k);
        return ans < 0 ? -1 : ans;
    }
};

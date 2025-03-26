class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size();
        int m = grid[0].size();
        sort(grid.begin(), grid.end());
        int mid_element = grid[n / 2][(m - 1) / 2];
        int MOD = grid[0][0] % x;
        int count = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                // already equal element
                if(i == n / 2 && j == (m - 1) / 2) continue;
                if(grid[i][j] % x != MOD) return -1;
                count += round(abs(grid[i][j] - mid_element) / x);
            }
        }

        return count;
    }
};
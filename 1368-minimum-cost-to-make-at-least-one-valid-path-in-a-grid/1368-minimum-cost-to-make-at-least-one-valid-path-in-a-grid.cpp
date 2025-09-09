class Solution {
public:
    bool inBounds(int row, int col, int m, int n) {
        return row >= 0 && col >= 0 && row < m && col < n;
    }
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        using T = tuple<int, int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;
        vector<vector<int>> cost(m, vector<int>(n, INT_MAX));
        pq.push({0, 0, 0});
        cost[0][0] = 0;
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while(!pq.empty()) {
            auto [c, row, col] = pq.top(); pq.pop();
            if(row == m - 1 && col == n - 1) return c;
            if(c > cost[row][col]) continue;
            for(int i = 0; i < 4; ++i) {
                int nrow = row + dir[i].first;
                int ncol = col + dir[i].second;
                if(!inBounds(nrow, ncol, m, n)) continue;
                int newCost = c + (grid[row][col] == i + 1 ? 0 : 1);
                if(newCost < cost[nrow][ncol]) {
                    pq.push({newCost, nrow, ncol});
                    cost[nrow][ncol] = newCost;
                }
            }
        }
        return cost[m-1][n-1];
    }
};
class Solution {
public:
    bool outOfBounds(int m, int n, int row, int col) {
        return row < 0 || col < 0 || row >= m || col >= n;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        unordered_map<int, vector<vector<int>>> mpp = {
            {1, {{0, -1}, {0, 1}}},
            {2, {{-1, 0}, {1, 0}}},
            {3, {{0, -1}, {1, 0}}},
            {4, {{0, 1}, {1, 0}}},
            {5, {{0, -1}, {-1, 0}}},
            {6, {{0, 1}, {-1, 0}}}
        };
        queue<pair<int, int>> q;
        q.push({0, 0});
        vis[0][0] = true;
        while(!q.empty()) {
            auto [row, col] = q.front(); q.pop();
            if(row == m - 1 && col == n - 1) return true;
            int type = grid[row][col];
            for(auto d : mpp[type]) {
                int nrow = row + d[0];
                int ncol = col + d[1];
                if(outOfBounds(m, n, nrow, ncol) || vis[nrow][ncol]) continue;

                bool flag = false;
                for(auto nd : mpp[grid[nrow][ncol]]) {
                    if(nd[0] == -d[0] && nd[1] == -d[1]) {
                        flag = true;
                        break;
                    }
                }
                if(!flag) continue;
                q.push({nrow, ncol});
                vis[nrow][ncol] = true;
            }
        }
        return false;
    }
};
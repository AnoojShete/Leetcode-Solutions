class Solution {
public:
    vector<int> delta = {-1, 0, 1, 0, -1};

    bool inBounds(int row, int col, int n) {
        return row >= 0 && col >= 0 && row < n && col < n;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        // Edge case:
        // If source or destination has thief
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return 0;
        // Compute minimum distance for every cell from the thief
        // And let's call it dist
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 1) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        // Now we start multisource BFS from every thief cell
        while(!q.empty()) {
            auto p = q.front(); q.pop();
            int row = p.first, col = p.second;
            int d = dist[row][col];
            for(int i = 0; i < 4; ++i) {
                int nrow = row + delta[i];
                int ncol = col + delta[i + 1];
                if(inBounds(nrow, ncol, n) && dist[nrow][ncol] > d + 1) {
                    dist[nrow][ncol] = d + 1;
                    q.push({nrow, ncol});
                }
            }
        }
        
        // Now perform Dijkstra's algorirhm from source
        // and pick maximum distance nodes from the thieves
        // Max Heap -> {dist, [x, y]}
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({dist[0][0], {0, 0}});
        vis[0][0] = true;
        while(!pq.empty()) {
            int d = pq.top().first;
            int row = pq.top().second.first, col = pq.top().second.second;
            pq.pop();

            if(row == n - 1 && col == n - 1) return d;
            for(int i = 0; i < 4; ++i) {
                int nrow = row + delta[i];
                int ncol = col + delta[i + 1];
                if(inBounds(nrow, ncol, n) && !vis[nrow][ncol]) {
                    int new_d = min(d, dist[nrow][ncol]);
                    vis[row][col] = true;
                    pq.push({new_d, {nrow, ncol}});
                }
            }
        }

        return -1;
    }
};
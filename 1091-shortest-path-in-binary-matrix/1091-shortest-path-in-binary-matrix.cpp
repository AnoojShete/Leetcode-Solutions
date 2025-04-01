class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return -1;
        if(n == 1) return 1;

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        // dist, {x, y}
        queue<pair<int, pair<int, int>>> q;

        q.push({0, {0, 0}});
        dist[0][0] = 0;
        while(!q.empty()) {
            auto p = q.front(); q.pop();
            int d = p.first;
            int row = p.second.first;
            int col = p.second.second;
            for(int i = -1; i <= 1; ++i) {
                for(int j = -1; j <= 1; ++j) {
                    int nrow = row + i;
                    int ncol = col + j;
                    if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < n
                     && grid[nrow][ncol] == 0 && (d + 1 < dist[nrow][ncol])) {
                        dist[nrow][ncol] = d + 1;
                        q.push({d + 1, {nrow, ncol}});
                        if(nrow == n - 1 && ncol == n - 1) return dist[nrow][ncol] + 1;
                    }
                }
            }
        }
        return -1;
    }
};
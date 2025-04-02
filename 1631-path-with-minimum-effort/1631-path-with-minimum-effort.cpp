class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        // [height -> x, y]
        priority_queue<pair<int, pair<int, int>>, 
        vector<pair<int, pair<int, int>>>, 
        greater<pair<int, pair<int, int>>>> q;

        q.push({0, {0, 0}});
        dist[0][0] = 0;

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, -1, 0, 1};

        while(!q.empty()) {
            auto p = q.top(); q.pop();
            int d = p.first;
            int row = p.second.first;
            int col = p.second.second;
            int h = heights[row][col];

            for(int i = 0; i < 4; ++i) {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m
                && abs(heights[nrow][ncol] - h) < dist[nrow][ncol]) {
                    dist[nrow][ncol] = abs(heights[nrow][ncol] - h);
                    q.push({dist[nrow][ncol], {nrow, ncol}});
                }
            }
        }
        return dist[n - 1][m - 1];
    }
};
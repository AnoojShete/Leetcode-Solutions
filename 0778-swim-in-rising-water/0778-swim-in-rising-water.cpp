class Solution {
public:
    bool inBounds(int row, int col, int n) {
        return row >= 0 && col >= 0 && row < n && col < n;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, 
        vector<pair<int, pair<int, int>>>, 
        greater<pair<int, pair<int, int>>>> pq;

        pq.push({grid[0][0], {0, 0}}); // Starting cell
        dist[0][0] = 0;

        int delta[] = {-1, 0, 1, 0, -1};
        while(!pq.empty()) {
            auto p = pq.top(); pq.pop();
            int time = p.first;
            int row = p.second.first;
            int col = p.second.second;

            if(row == n - 1 && col == n -1) return time;

            for(int i = 0; i < 4; ++i) {
                int nrow = row + delta[i];
                int ncol = col + delta[i+1];
                if(inBounds(nrow, ncol, n)) {
                    int newTime = max(time, grid[nrow][ncol]);
                    if(newTime < dist[nrow][ncol]) {
                        dist[nrow][ncol] = newTime;
                        pq.push({newTime, {nrow, ncol}});
                    }
                }
            }
        }

        return -1;
    }
};
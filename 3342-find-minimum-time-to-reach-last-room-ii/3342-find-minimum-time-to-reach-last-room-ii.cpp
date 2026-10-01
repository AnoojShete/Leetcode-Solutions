class Solution {
public:
    bool inBounds(int row, int col, int m, int n) {
        return row >= 0 && col >= 0 && row < m && col < n;
    }
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size(), n = moveTime[0].size();
        using T = tuple<int, int, int>;
        priority_queue<T, vector<T>, greater<>> pq;
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        pq.push({0, 0, 0});
        dist[0][0] = 0;
        int delta[] = {-1, 0, 1, 0, -1};
        while(!pq.empty()) {
            auto [t, row, col] = pq.top(); pq.pop();
            if(t > dist[row][col]) continue;
            if(row == m - 1 && col == n - 1) return t;
            for(int i = 0; i < 4; ++i) {
                int nrow = row + delta[i];
                int ncol = col + delta[i+1];
                if(inBounds(nrow, ncol, m, n)) {
                    int newTime = max(t, moveTime[nrow][ncol]) + ((row + col) % 2 + 1);
                    if(newTime < dist[nrow][ncol]) {
                        dist[nrow][ncol] = newTime;
                        pq.push({newTime, nrow, ncol});
                    }
                }
            }
        }
        return -1;
    }
};
typedef pair<int, int> pii;

class Solution {
public:
    bool inBounds(int row, int col, int n, int m) {
        return row >= 0 && col >= 0 && row < n && col < m;
    }

    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<>> pq;

        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        int delta[] = {-1, 0, 1, 0, -1};

        while (!pq.empty()) {
            auto [t, pos] = pq.top(); pq.pop();
            int row = pos.first, col = pos.second;

            if (row == n - 1 && col == m - 1) return t;
            if (t > dist[row][col]) continue;

            for (int i = 0; i < 4; ++i) {
                int nrow = row + delta[i], ncol = col + delta[i + 1];
                if (inBounds(nrow, ncol, n, m)) {
                    int nextTime = t + 1;

                    if (nextTime < moveTime[nrow][ncol])
                        nextTime = moveTime[nrow][ncol];

                    if ((nextTime - moveTime[nrow][ncol]) % 2 == 1)
                        nextTime += 1;

                    if (nextTime < dist[nrow][ncol]) {
                        dist[nrow][ncol] = nextTime;
                        pq.push({nextTime, {nrow, ncol}});
                    }
                }
            }
        }

        return -1;
    }
};

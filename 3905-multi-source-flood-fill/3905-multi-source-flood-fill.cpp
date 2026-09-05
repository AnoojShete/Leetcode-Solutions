class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        vector<vector<int>> ans(n, vector<int>(m, -1));
        queue<pair<int, int>> q;
        for(auto &source : sources) {
            int r = source[0], c = source[1], col = source[2];
            dist[r][c] = 0;
            ans[r][c] = max(ans[r][c], col);
            q.push({r, c});
        }
        int d = 0;
        int delta[] = {-1, 0, 1, 0, -1};
        auto inBounds = [&](int r, int c) {
            return r >= 0 && c >= 0 && r < n && c < m;
        };
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto [r, c] = q.front(); q.pop();
                int col = ans[r][c];
                for(int i = 0; i < 4; ++i) {
                    int nr = r + delta[i], nc = c + delta[i+1];
                    if(inBounds(nr, nc)) {
                        if(dist[nr][nc] > d + 1) {
                            dist[nr][nc] = d + 1;
                            ans[nr][nc] = col;
                            q.push({nr, nc});
                        }
                        else if(dist[nr][nc] == d + 1) {
                            ans[nr][nc] = max(ans[nr][nc], col);
                        }
                    }
                }
            }
            d++;
        }
        return ans;
    }
};
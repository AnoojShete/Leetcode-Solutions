class Solution {
public:
    bool inBounds(int row, int col, int n, int m) {
        return row >= 0 && col >= 0 && row < n && col < m;
    }
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int n = grid.size(), m = grid[0].size();
        vector<pair<int, int>> sorted_queries;
        for(int i = 0; i < queries.size(); ++i) {
            sorted_queries.push_back({queries[i], i});
        }
        sort(sorted_queries.begin(), sorted_queries.end());
        vector<int> ans(queries.size());

        priority_queue<pair<int, pair<int, int>>, 
        vector<pair<int, pair<int, int>>>, greater<>> pq;

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        
        pq.push({grid[0][0], {0, 0}});
        vis[0][0] = true;

        int count = 0;
        int delta[] = {-1, 0, 1, 0, -1};
        for(auto &p : sorted_queries) {
            int val = p.first;
            int idx = p.second;

            while(!pq.empty() && pq.top().first < val) {
                int val1 = pq.top().first;
                int row = pq.top().second.first;
                int col = pq.top().second.second;
                pq.pop();

                count++;
                for(int i = 0; i < 4; ++i) {
                    int nrow = row + delta[i];
                    int ncol = col + delta[i + 1];
                    if(inBounds(nrow, ncol, n, m) && !vis[nrow][ncol]) {
                        pq.push({grid[nrow][ncol], {nrow, ncol}});
                        vis[nrow][ncol] = true;
                    }
                }
            }
            ans[idx] = count;
        }

        return ans;
    }
};
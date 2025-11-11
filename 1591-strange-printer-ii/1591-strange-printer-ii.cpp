class Solution {
public:
    bool isPrintable(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> minR(61, m), minC(61, n), maxR(61, -1), maxC(61, -1);
        unordered_set<int> st;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                int c = grid[i][j];
                st.insert(c);
                minR[c] = min(minR[c], i);
                minC[c] = min(minC[c], j);
                maxR[c] = max(maxR[c], i);
                maxC[c] = max(maxC[c], j);
            }
        }
        int totColors = st.size();
        vector<int> indegree(61, 0);
        vector<vector<int>> adj(61);
        for(auto c : st) {
            for(int i = minR[c]; i <= maxR[c]; ++i) {
                for(int j = minC[c]; j <= maxC[c]; ++j) {
                    int d = grid[i][j];
                    if(d != c) {
                        adj[c].push_back(d);
                    }
                }
            }
        }
        for (int i = 0; i < 61; ++i) {
            sort(adj[i].begin(), adj[i].end());
            adj[i].erase(unique(adj[i].begin(), adj[i].end()), adj[i].end());
            for (int d : adj[i]) indegree[d]++;
        }
        queue<int> q;
        for(int c : st) if(indegree[c] == 0) q.push(c);
        int count = 0;
        while(!q.empty()) {
            int color = q.front(); q.pop();
            count++;
            for(int nei : adj[color]) {
                if(--indegree[nei] == 0) q.push(nei);
            }
        }
        return count == totColors;
    }
};
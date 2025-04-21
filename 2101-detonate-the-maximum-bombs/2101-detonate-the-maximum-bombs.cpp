class Solution {
public:
    bool isInRange(int x1, int y1, int r, int x2, int y2) {
        return (pow((x1 - x2), 2) + pow((y1 - y2), 2)) <= r*r;
    }
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis, int &count) {
        vis[node] = true;
        count++;
        for(auto &it : adj[node]) {
            if(!vis[it]) {
                dfs(it, adj, vis, count);
            }
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n);
        // Making graph
        for(int i = 0; i < n; ++i) {
            vector<int> bomb = bombs[i];
            int x1 = bomb[0], y1 = bomb[1], r = bomb[2];
            for(int j = 0; j < n; ++j) {
                vector<int> neigh = bombs[j];
                int x2 = neigh[0], y2 = neigh[1];
                if(isInRange(x1, y1, r, x2, y2)) {
                    adj[i].push_back(j);
                }
            }
        }

        int maxCount = 0;
        for(int i = 0; i < n; ++i) {
            int count = 0;
            vector<bool> vis(n, false);
            dfs(i, adj, vis, count);
            maxCount = max(maxCount, count);
        }

        return maxCount;
    }
};
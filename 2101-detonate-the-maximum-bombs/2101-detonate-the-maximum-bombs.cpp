typedef long long ll;

class Solution {
public:
    bool isInRange(int x1, int y1, int r, int x2, int y2) {
        ll x = pow((x1 - x2), 2), y = pow((y1 - y2), 2);
        ll rad = r;
        rad *= r;
        return (x + y) <= rad;
    }
    int dfs(int node, vector<vector<int>> &adj, vector<bool> &vis) {
        vis[node] = true;
        int count = 1;
        for(auto &it : adj[node]) {
            if(!vis[it]) {
                count += dfs(it, adj, vis);
            }
        }

        return count;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n);
        // Making graph
        for(int i = 0; i < n; ++i) {
            vector<int> bomb = bombs[i];
            int x1 = bomb[0], y1 = bomb[1], r = bomb[2];
            for(int j = 0; j < n; ++j) {
                if(i == j) continue;
                vector<int> neigh = bombs[j];
                int x2 = neigh[0], y2 = neigh[1];
                if(isInRange(x1, y1, r, x2, y2)) {
                    adj[i].push_back(j);
                }
            }
        }

        int maxCount = 0;
        for(int i = 0; i < n; ++i) {
            vector<bool> vis(n, false);
            int count = dfs(i, adj, vis);
            maxCount = max(maxCount, count);
        }

        return maxCount;
    }
};
class Solution {
public:
    double ans = 0;
    void dfs(int parent, int node, vector<vector<int>> &adj, 
    int currTime, int t, int target, double p) {
        if(node == target) {
            if (currTime == t || (currTime < t && adj[node].size() == 0)) {
                ans = p;
            }
            return;
        }
        int child = 0;
        for (auto it : adj[node]) if (it != parent) child++;
        for (auto it : adj[node]) {
            if (it == parent) continue;
            dfs(node, it, adj, currTime + 1, t, target, p / child);
        }
    }
    
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            int u = e[0]-1, v = e[1]-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(-1, 0, adj, 0, t, target-1, 1.0);
        return ans;
    }
};
class Solution {
public:
    int timer = 0;

    void dfs(int node, int parent, vector<vector<int>> &adj, vector<bool> &vis,
    vector<int> &tin, vector<int> &low, vector<vector<int>> &ans) {
        vis[node] = true;
        tin[node] = low[node] = timer;
        timer++;
        for(auto &it : adj[node]) {
            if(it == parent) continue;
            if(!vis[it]) {
                dfs(it, node, adj, vis, tin, low, ans);
                low[node] = min(low[node], low[it]);
                if(low[it] > tin[node]) {
                    ans.push_back({node, it});
                }
            }
            else {
                low[node] = min(low[node], tin[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto &con : connections) {
            adj[con[0]].push_back(con[1]);
            adj[con[1]].push_back(con[0]);
        }

        vector<int> low(n), tin(n);
        vector<bool> vis(n, false);
        vector<vector<int>> ans;
        // Assuming graph is a single component

        dfs(0, -1, adj, vis, tin, low, ans);

        return ans;
    }
};
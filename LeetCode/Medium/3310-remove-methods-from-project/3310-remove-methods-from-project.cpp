class Solution {
public:
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis) {
        vis[node] = true;
        for(auto &it : adj[node]) {
            if(!vis[it]) dfs(it, adj, vis);
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for(auto &e : invocations) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
        }
        vector<bool> vis(n, false);
        dfs(k, adj, vis);
        bool flag = true;
        for(int i = 0; i < n; ++i) {
            if(!vis[i]) {
                for(auto it : adj[i]) {
                    if(vis[it]) {flag = false;break;}
                }
            }
        }
        vector<int> ans;
        if(flag) {
            for(int i = 0; i < n; ++i)
                if(!vis[i])
                    ans.push_back(i);
        }
        else for(int i = 0; i < n; ++i) ans.push_back(i);
        return ans;
    }
};
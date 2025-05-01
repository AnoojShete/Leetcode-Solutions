class Solution {
public:
    int dfs(int node, vector<vector<int>> &adj, vector<bool> &vis) {
        vis[node] = true;
        int count = 1;
        for(auto it : adj[node]) {
            if(!vis[it]) {
                count += dfs(it, adj, vis);
            }
        }

        return count;
    } 
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        unordered_set<int> st(restricted.begin(), restricted.end());
        vector<vector<int>> adj(n);
        for(auto &e : edges) {
            if(st.find(e[0]) != st.end() || st.find(e[1]) != st.end()) continue;
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool> vis(n, false);
        return dfs(0, adj, vis);
    }
};
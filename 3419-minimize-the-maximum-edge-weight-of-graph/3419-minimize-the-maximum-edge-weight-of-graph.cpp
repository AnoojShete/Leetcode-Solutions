class Solution {
public:
    int dfs(int node, vector<vector<pair<int, int>>> &adj, vector<bool> &vis, int mid) {
        int nodes = 1;
        vis[node] = true;
        for(auto &[nei, wt] : adj[node]) {
            if(wt <= mid && !vis[nei]) nodes += dfs(nei, adj, vis, mid);
        }
        return nodes;
    }
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto &e : edges) {
            adj[e[1]].push_back({e[0], e[2]});
        }
        int low = 1, high = 1e6+1;
        while(low < high) {
            vector<bool> vis(n, false);
            int mid = (low + high) / 2;
            if(dfs(0, adj, vis, mid) == n) high = mid;
            else low = mid + 1;
        }
        return low == 1e6+1 ? -1 : low;
    }
};
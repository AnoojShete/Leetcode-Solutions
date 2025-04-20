class Solution {
public:
    int count = 0;
    void dfs(int node, vector<vector<int>> &adj, unordered_set<int> &vis) {
        vis.insert(node);
        for(auto &it : adj[node]) {
            if(vis.find(abs(it)) == vis.end()) {
                if(it > 0) {
                    count++;
                }
                dfs(abs(it), adj, vis);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto &e : connections) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(-e[0]);
        }
        unordered_set<int> vis;
        dfs(0, adj, vis);

        return count;
    }
};
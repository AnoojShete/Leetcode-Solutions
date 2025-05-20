class Solution {
public:
    bool isValid(int node, vector<vector<int>> &adj, vector<int> &flowers, int f) {
        for(auto &it : adj[node]) {
            if(flowers[it] == f) return false;
        }
        return true;
    }
    bool dfs(int node, vector<vector<int>> &adj, vector<int> &flowers) {
        if(node == adj.size()) return true;
        for(int f = 1; f <= adj.size(); ++f) {
            if(isValid(node, adj, flowers, f)) {
                flowers[node] = f;
                if(dfs(node + 1, adj, flowers)) return true;
                flowers[node] = -1;
            }
        }

        return false;
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n + 1);
        for(auto &e : paths) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> flowers(n + 1, -1);
        dfs(0, adj, flowers);
        flowers.erase(flowers.begin());
        return flowers;
    }
};
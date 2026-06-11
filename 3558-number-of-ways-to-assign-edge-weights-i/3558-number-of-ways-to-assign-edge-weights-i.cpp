class Solution {
public:
    int power(int base, int exp, int mod) {
        long long result = 1;
        long long b = base;
        while (exp > 0) {
            if (exp % 2 == 1) result = (result * b) % mod;
            b = (b * b) % mod;
            exp /= 2;
        }
        return result;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n + 2);
        for(auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        function<int(int, int)> dfs = [&](int node, int par) {
            int d = 0;
            for(auto nei : adj[node])
                if(nei != par)
                    d = max(d, 1 + dfs(nei, node));
            return d;
        };
        return power(2, dfs(1, -1) - 1, 1e9 + 7);
    }
};
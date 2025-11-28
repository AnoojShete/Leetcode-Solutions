class Solution {
public:
    int count = 0;
    long long solve(int parent, int node, vector<vector<int>> &adj, vector<int> &values, int k) {
        long long sum = values[node];
        for(auto &nei : adj[node]) {
            if(nei == parent) continue;
            sum += solve(node, nei, adj, values, k);
        }
        if(sum % k == 0) {
            count++;
            return 0;
        }
        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for(auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        solve(-1, 0, adj, values, k);
        return count;
    }
};
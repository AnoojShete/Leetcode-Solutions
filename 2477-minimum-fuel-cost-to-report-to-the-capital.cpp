typedef long long ll;

class Solution {
public:
    ll fuel = 0;
    int dfs(int node, int parent, vector<vector<int>> &adj, int seats) {
        int ppl = 1;
        for(auto &it : adj[node]) {
            if(it == parent) continue;
            int subPpl = dfs(it, node, adj, seats);
            ppl += subPpl;
            fuel += (subPpl + seats - 1) / seats;
        }
        return ppl;
    }
    ll minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        vector<vector<int>> adj(n);
        for(auto &e : roads) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        dfs(0, -1, adj, seats);
        return fuel;
    }
};
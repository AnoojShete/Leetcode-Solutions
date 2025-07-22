class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        vector<vector<pair<int, int>>> adj(n);
        for(int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back({v, vals[v]});
            adj[v].push_back({u, vals[u]});
        }
        int ans = INT_MIN;
        for(int node = 0; node < n; ++node) {
            vector<pair<int, int>> nei = adj[node];
            sort(nei.begin(), nei.end(), [](auto &p1, auto &p2){return p1.second > p2.second;});
            int sum = vals[node];
            for(int i = 0; i < k && i < nei.size(); ++i) {
                if(nei[i].second < 0) break;
                sum += nei[i].second;
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};
class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, 2 * w});
        }
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        dist[0] = 0;
        pq.push({0, 0});
        while(!pq.empty()) {
            auto [d, node] = pq.top(); pq.pop();
            if(d != dist[node]) continue;
            if(node == n - 1) return d;
            for(auto &[nei, w] : adj[node]) {
                int newDist = d + w;
                if(dist[nei] > newDist) {
                    pq.push({newDist, nei});
                    dist[nei] = newDist;
                }
            }
        }
        return -1;
    }
};
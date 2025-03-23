typedef pair<long, long> pll;
typedef long long ll;

class Solution {
public:
    int MOD = 1e9 + 7;
    int dijkstra(int n, vector<vector<pll>> &adj, int src) {
        vector<ll> dist(n, LONG_MAX);
        vector<ll> ways(n);
        dist[src] = 0;
        ways[src] = 1;
        priority_queue<pll, vector<pll>, greater<pll>> pq;
        pq.push({0, 0}); 
        while(!pq.empty()) {
            auto p = pq.top(); pq.pop();
            ll d = p.first, u = p.second;

            if(d > dist[u]) continue;

            for(auto &[v, time] : adj[u]) {
                if(dist[v] > d + time) {
                    dist[v] = d + time;
                    ways[v] = ways[u];
                    pq.push({dist[v], v});
                }
                else if(dist[v] == d + time) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }
        return ways[n - 1];
    }
    int countPaths(int n, vector<vector<int>>& roads) {
        // <distance, node>
        vector<vector<pll>> adj(n);
        for(auto &road : roads) {
            ll u = road[0], v = road[1], time = road[2];
            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }

        return dijkstra(n, adj, 0);
    }
};
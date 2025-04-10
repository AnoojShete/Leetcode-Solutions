typedef pair<long, long> pll;
class Solution {
public:
    const long long MOD = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pll>> adj(n);
        for(auto &e : roads) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        priority_queue<pll, vector<pll>, greater<pll>> pq;
        vector<long long> dist(n, LLONG_MAX); // Use long long for large distances
        vector<long long> ways(n, 0);

        pq.push({0, 0});
        dist[0] = 0;
        ways[0] = 1;

        while(!pq.empty()) {
            int node = pq.top().second;
            long long d = pq.top().first;
            pq.pop();

            if(d > dist[node]) continue;

            for(auto it : adj[node]) {
                int neigh = it.first;
                long long nd = it.second;
                long long newd = d + nd;

                if(newd < dist[neigh]) {
                    dist[neigh] = newd;
                    ways[neigh] = ways[node];
                    pq.push({dist[neigh], neigh});
                }
                else if(newd == dist[neigh]) {
                    ways[neigh] = (ways[neigh] + ways[node]) % MOD;
                }
            }
        }
        return ways[n - 1];
    }
};

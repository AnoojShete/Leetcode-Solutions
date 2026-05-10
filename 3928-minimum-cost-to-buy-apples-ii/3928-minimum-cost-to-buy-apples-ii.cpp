typedef long long ll;

class Solution {
public:
    vector<int> minCost(int n, vector<int>& prices, vector<vector<int>>& roads) {
        if(roads.empty()) return prices;
        vector<int> ans(n);
        using T = tuple<int, int, int>;
        vector<vector<T>> adj(n);
        for(auto &r : roads) {
            int u = r[0], v = r[1], c = r[2], t = r[3];
            adj[u].push_back({v, c, t});
            adj[v].push_back({u, c, t});
        }
        for(int i = 0; i < n; ++i) {
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
            vector<ll> dist(n, LLONG_MAX);
            pq.push({0, i});
            dist[i] = 0;
            while(!pq.empty()) {
                auto [cost, node] = pq.top(); pq.pop();
                if(cost > dist[node]) continue;
                for(auto &[nei, c, t] : adj[node]) {
                    if(dist[node] + c < dist[nei]) {
                        dist[nei] = dist[node] + c;
                        pq.push({dist[nei], nei});
                    }
                }
            }
            vector<ll> dist2(n, LLONG_MAX);
            pq.push({0, i});
            dist2[i] = 0;
            while(!pq.empty()) {
                auto [cost, node] = pq.top(); pq.pop();
                if(cost > dist2[node]) continue;
                for(auto &[nei, c, t] : adj[node]) {
                    if(dist2[node] + 1LL * c * t < dist2[nei]) {
                        dist2[nei] = dist2[node] + 1LL * c * t;
                        pq.push({dist2[nei], nei});
                    }
                }
            }
            ll best = prices[i];
            for(int j = 0; j < n; ++j) {
                if(dist[j] == LLONG_MAX || dist2[j] == LLONG_MAX) continue;
                best = min(best, dist[j] + prices[j] + dist2[j]);
            }
            ans[i] = (int)best;
        }
        return ans;
    }
};
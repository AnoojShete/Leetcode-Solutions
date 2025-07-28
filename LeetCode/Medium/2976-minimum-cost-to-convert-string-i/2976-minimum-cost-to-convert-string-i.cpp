typedef long long ll;

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = cost.size();
        vector<vector<ll>> dist(26, vector<ll>(26, LLONG_MAX));
        for(int i = 0; i < 26; ++i) dist[i][i] = 0;
        for (int i = 0; i < n; ++i) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            dist[u][v] = min(dist[u][v], (ll)cost[i]);
        }
        for(int k = 0; k < 26; ++k) {
            for(int i = 0; i < 26; ++i) {
                for(int j = 0; j < 26; ++j) {
                    if(dist[i][k] != LLONG_MAX && dist[k][j] != LLONG_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        ll ans = 0;
        int m = source.size();
        for (int i = 0; i < m; ++i) {
            if (source[i] == target[i]) continue;
            int u = source[i] - 'a', v = target[i] - 'a';
            if (dist[u][v] == LLONG_MAX) return -1;
            ans += dist[u][v];
        }
        return ans;
    }
};
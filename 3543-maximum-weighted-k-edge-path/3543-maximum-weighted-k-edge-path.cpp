class Solution {
public:
    static const int MAXT = 600;
    int maxWeight(int n, vector<vector<int>>& edges, int k, int t) {
        vector<bitset<MAXT>> dp(n);
        for(int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }
        for(int step = 0; step < k; step++) {
            vector<bitset<MAXT>> next(n);
            for(auto &e : edges) {
                int u = e[0];
                int v = e[1];
                int w = e[2];
                next[v] |= (dp[u] << w);
            }
            for(int i = 0; i < n; i++) {
                for(int s = t; s < MAXT; s++) {
                    next[i][s] = 0;
                }
            }
            dp = move(next);
        }
        for(int sum = t - 1; sum >= 0; sum--) {
            for(int node = 0; node < n; node++) {
                if(dp[node][sum]) {
                    return sum;
                }
            }
        }
        return -1;
    }
};

/*
TLE:
class Solution {
public:
    int maxWeight(int n, vector<vector<int>>& edges, int k, int t) {
        vector<vector<bool>> dp(n, vector<bool>(t, false));
        for(int i = 0; i < n; ++i) dp[i][0] = true;
        for(int i = 0; i < k; ++i) {
            vector<vector<bool>> next(n, vector<bool>(t, false));
            for(auto &e : edges) {
                int u = e[0], v = e[1], w = e[2];
                for(int sum = 0; sum + w < t; ++sum) {
                    if(dp[u][sum]) next[v][sum + w] = true;
                }
            }
            dp = next;
        }
        int ans = -1;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < t; ++j) if(dp[i][j]) ans = max(ans, j);
        }
        return ans;
    }
};
now?
*/
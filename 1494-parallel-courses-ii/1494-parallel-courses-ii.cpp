class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        vector<int> prereq(n, 0);
        for(auto &e : relations) {
            int u = e[0] - 1, v = e[1] - 1;
            prereq[v] |= (1 << u);
        }
        vector<int> dp((1 << n), INT_MAX);
        dp[0] = 0;
        for(int mask = 0; mask < (1 << n); ++mask) {
            if(dp[mask] == INT_MAX) continue;
            int available = 0;
            for(int i = 0; i < n; ++i) {
                ifmask & (1 << i)) && ((mask & prereq[i]) == prereq[i])) {
                    available |= (1 << i);
                }
            }
            int count = __builtin_popcount(available);
            if(count <= k) {
                dp[mask | available] = min(dp[mask | available], 1 + dp[mask]);
            }
            else {
                // avaiable C k combinations
                for(int i = available; i; i = (i - 1) & available) {
                    if(__builtin_popcount(i) <= k)
                        dp[mask | i] = min(dp[mask | i], 1 + dp[mask]);
                }
            }
        }
        return dp[(1 << n) - 1];
    }
};
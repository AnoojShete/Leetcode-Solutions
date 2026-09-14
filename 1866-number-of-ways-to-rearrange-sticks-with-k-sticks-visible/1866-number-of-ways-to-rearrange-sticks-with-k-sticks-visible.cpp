#define ll long long
class Solution {
public:
    int rearrangeSticks(int n, int k) {
        const int mod = 1e9 + 7;
        vector<vector<ll>> dp(n+1, vector<ll>(k+1));
        dp[1][1] = 1;
        for(int i = 2; i <= n; ++i) {
            for(int j = 1; j <= min(i, k); ++j) {
                dp[i][j] = (dp[i-1][j-1] + (i-1)*dp[i-1][j]) % mod;
            }
        }
        return dp[n][k];
    }
};
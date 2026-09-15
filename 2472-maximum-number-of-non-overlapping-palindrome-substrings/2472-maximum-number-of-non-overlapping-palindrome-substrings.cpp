class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.length();
        vector<vector<bool>> isValid(n, vector<bool>(n, false));
        for(int i = 0; i < n; ++i) {
            for(int j = i; j >= 0; --j) {
                if(s[i] == s[j] && (i - j + 1 <= 2 || isValid[j+1][i-1]))
                    isValid[j][i] = true;
            }
        }
        int dp[2001];
        dp[n] = 0;
        for(int i = n-1; i >= 0; --i) {
            dp[i] = dp[i+1];
            for(int j = i+k-1; j < n; ++j) {
                if(isValid[i][j]) dp[i] = max(dp[i], 1 + dp[j + 1]);
            }
        }
        return dp[0];
    }
};
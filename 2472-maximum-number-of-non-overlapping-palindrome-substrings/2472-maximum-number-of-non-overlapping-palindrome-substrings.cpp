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
        memset(dp, -1, sizeof dp);
        function<int(int)> solve = [&](int i) -> int {
            if(i == n) return 0;
            if(dp[i] != -1) return dp[i];
            int ans = solve(i + 1);
            for(int j = i + k - 1; j < n; ++j) {
                if(isValid[i][j]) ans = max(ans, 1 + solve(j + 1));
            }
            return dp[i] = ans;
        };
        return solve(0);
    }
};
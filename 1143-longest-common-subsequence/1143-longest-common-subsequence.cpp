class Solution {
public:
    int memo[1001][1001];
    int solve(int n, int m, string &x, string &y) {
        if(n == 0 || m == 0) return 0;
        if(memo[n][m] != -1) return memo[n][m];
        if(x[n-1] == y[m-1]) {
            return memo[n][m] = 1 + solve(n-1, m-1, x, y);
        }
        return memo[n][m] = max(solve(n-1, m, x, y), solve(n, m-1, x, y));
    }
    int longestCommonSubsequence(string x, string y) {
        int n = x.length(), m = y.length();
        memset(memo, -1, sizeof memo);
        return solve(n, m, x, y);
    }
};
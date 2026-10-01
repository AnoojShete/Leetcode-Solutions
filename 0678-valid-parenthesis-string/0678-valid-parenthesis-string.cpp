class Solution {
public:
    int dp[101][101];
    bool solve(int i, string &s, int count) {
        if(count < 0) return false;
        if(i == s.length()) {
            if(count == 0) return true;
            return false;
        }
        if(dp[i][count] != -1) return dp[i][count];
        bool choice = false;
        if(s[i] == '*') {
            return dp[i][count] = solve(i + 1, s, count) || solve(i + 1, s, count - 1) || solve(i + 1, s, count + 1);
        }
        else if(s[i] == '(') return dp[i][count] = solve(i + 1, s, count + 1);
        return dp[i][count] = solve(i + 1, s, count - 1);
    }
    bool checkValidString(string s) {
        memset(dp, -1, sizeof dp);
        return solve(0, s, 0);
    }
};
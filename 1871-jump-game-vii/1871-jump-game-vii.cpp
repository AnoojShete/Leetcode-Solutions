class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        if(s[0] != '0' || s[n-1] != '0') return false;
        vector<bool> dp(n, false);
        dp[0] = true;
        int count = 0;
        for(int i = 0; i < n; ++i) {
            if(i - minJump >= 0) count += dp[i - minJump];
            if(i - maxJump - 1 >= 0) count -= dp[i - maxJump - 1];
            if(count && s[i] == '0') dp[i] = true;
        }
        return dp[n-1];
    }
};
class Solution {
public:
    int solve(int idx, vector<int> &energy, int k, vector<int> &dp) {
        if(idx >= energy.size()) return 0;
        if(dp[idx] != INT_MIN) return dp[idx];
        int take = energy[idx] + solve(idx + k, energy, k, dp);
        return dp[idx] = take;
    }
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int> dp(n, INT_MIN);
        int ans = INT_MIN;
        for(int i = 0; i < n; ++i) {
            ans = max(ans, solve(i, energy, k, dp));
        }
        return ans;
    }
};
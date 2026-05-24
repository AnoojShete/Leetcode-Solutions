class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n, -1);
        
        function<int(int)> dfs = [&](int idx) {
            if(dp[idx] != -1) return dp[idx];
            int ans = 1;
            for(int i = idx + 1; i <= idx + d && i < n; ++i) {
                if(arr[i] >= arr[idx]) break;
                ans = max(ans, 1 + dfs(i));
            }
            for(int i = idx - 1; i >= idx - d && i >= 0; --i) {
                if(arr[i] >= arr[idx]) break;
                ans = max(ans, 1 + dfs(i));
            }
            return dp[idx] = ans;
        };
        int ans = 1;
        for(int i = 0; i < n; ++i) ans = max(ans, dfs(i));
        return ans;
    }
};
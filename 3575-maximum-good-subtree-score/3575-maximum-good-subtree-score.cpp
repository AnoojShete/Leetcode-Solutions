class Solution {
public:
    int MOD = 1e9 + 7;
    int dp[501][1025];
    bool check(int val, int bitMask) {
        while(val) {
            int d = val % 10;
            if(bitMask & 1 << d) return false;
            val /= 10;
        }
        return true;
    }
    int set_bitMask(int val, int bitMask) {
        while(val) {
            int d = val % 10;
            if(bitMask & 1 << d) return -1;
            bitMask |= 1 << d;
            val /= 10;
        }
        return bitMask;
    }
    void dfs(int node, vector<vector<int>> &adj,
    vector<int> &vals, vector<int> &v) {
        v.push_back(vals[node]);
        for(auto it : adj[node]) {
            dfs(it, adj, vals, v);
        }
    }
    int maxSum(int idx, vector<int> &v, int bitMask) {
        if(idx >= v.size()) return 0;
        if(dp[idx][bitMask] != -1) return dp[idx][bitMask];
        int notTake = maxSum(idx + 1, v, bitMask);
        int take = 0;
        if(check(v[idx], bitMask)) {
            int newMask = set_bitMask(v[idx], bitMask);
            if(newMask != -1) {
                take = v[idx] + maxSum(idx + 1, v, newMask);
            }
        }
        return dp[idx][bitMask] = max(take, notTake);
    }
    int goodSubtreeSum(vector<int>& vals, vector<int>& par) {
        int n = vals.size();
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; ++i) {
            if(par[i] != -1) adj[par[i]].push_back(i);
        }
        int ans = 0;
        for(int node = 0; node < n; ++node) {
            memset(dp, -1, sizeof dp);
            vector<int> v;
            dfs(node, adj, vals, v);
            ans = (ans + maxSum(0, v,  0)) % MOD;
        }
        return ans;
    }
};
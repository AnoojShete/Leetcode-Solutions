class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        for(auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }
        queue<int> q;
        for(int i = 0; i < n; ++i) if(indegree[i] == 0) q.push(i);
        
        vector<int> topoSort;
        while(!q.empty()) {
            int node = q.front(); q.pop();
            topoSort.push_back(node);
            for(auto &it : adj[node]) {
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        if(topoSort.size() != n) return -1;

        vector<vector<int>> dp(n, vector<int>(26, 0));
        for(int i = 0; i < n; ++i) dp[i][colors[i] - 'a'] = 1;

        int maxi = 0;
        for(auto node : topoSort) {
            for(auto it : adj[node]) {
                for(int c = 0; c < 26; ++c) {
                    int val = dp[node][c] + (colors[it] - 'a' == c ? 1 : 0);
                    dp[it][c] = max(dp[it][c], val);
                }
            }
            maxi = max(maxi, *max_element(dp[node].begin(), dp[node].end()));
        }

        return maxi;
    }
};
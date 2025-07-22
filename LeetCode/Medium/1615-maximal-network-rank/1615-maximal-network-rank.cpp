class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0);
        set<pair<int, int>> st;
        for(auto &e : roads) {
            int u = e[0], v = e[1];
            degree[u]++, degree[v]++;
            if(u > v) swap(u, v);
            st.insert({u, v});
        }
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                if(st.find({i, j}) != st.end()) ans = max(ans, degree[i]+degree[j]-1);
                else ans = max(ans, degree[i]+degree[j]);
            }
        }
        return ans;
    }
};
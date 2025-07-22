class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, 
    vector<vector<int>>& blueEdges) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto &e : redEdges) adj[e[0]].push_back({e[1], 0});
        for(auto &e : blueEdges) adj[e[0]].push_back({e[1], 1});
        queue<pair<int, int>> q;
        q.push({0, 1});
        q.push({0, 0});
        vector<int> ans(n, -1);
        ans[0] = 0;
        int d = 0;
        vector<vector<bool>> vis(n, vector<bool>(2, false));
        vis[0][0] = vis[0][1] = true;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto [node, color] = q.front(); q.pop();
                if(ans[node] == -1) ans[node] = d;
                for(auto &[it, c] : adj[node]) {
                    if(c != color && !vis[it][c]) {
                        q.push({it, c});
                        vis[it][c] = true;
                    }
                }
            }
            d++;
        }
        for(auto &it : ans) if(it == INT_MAX) it = -1;
        return ans;
    }
};
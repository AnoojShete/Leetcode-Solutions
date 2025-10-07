class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int fullMask = (1 << n) - 1;
        vector<vector<bool>> vis(n, vector<bool>((1 << n), false));
        queue<pair<int, int>> q;
        for(int i = 0; i < n; ++i) {
            q.push({i, 1 << i});
            vis[i][1 << i] = true;
        }
        int level = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto [node, currMask] = q.front(); q.pop();
                if(currMask == fullMask) return level;
                for(auto &it : graph[node]) {
                    int nextMask = currMask | (1 << it);
                    if(!vis[it][nextMask]) {
                        q.push({it, nextMask});
                        vis[it][nextMask] = true;
                    }
                }
            }
            level++;
        }
        return -1;
    }
};
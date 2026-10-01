class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        vector<int> ans(queries.size(), -1);
        for(int i = 0; i < queries.size(); ++i) {
            int u = queries[i][0], v = queries[i][1];
            adj[u].push_back(v);
            vector<bool> vis(n,false);
            queue<int> q;
            q.push(0);
            vis[0] = true;
            int moves = 0;
            while(!q.empty()) {
                if(ans[i] != -1) break;
                int sz = q.size();
                while(sz--) {
                    int node = q.front(); q.pop();
                    if(node == n-1) {
                        ans[i] = moves;
                        break;
                    }
                    if(!vis[node+1]) q.push(node + 1);
                    for(auto &it : adj[node]) {
                        if(!vis[it]) {
                            q.push(it);
                            vis[it] = true;
                        }
                    }
                }
                moves++;
            }
        }
        return ans;
    }
};
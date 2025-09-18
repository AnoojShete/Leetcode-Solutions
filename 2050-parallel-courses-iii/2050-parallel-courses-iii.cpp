class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        for(auto &e : relations) {
            int u = e[0]-1, v = e[1]-1;
            adj[u].push_back(v);
            indegree[v]++;
        }
        int ans = 0;
        queue<int> q;
        for(int i = 0; i < n; ++i) if(indegree[i] == 0) q.push(i);
        while(!q.empty()) {
            int sz = q.size();
            int maxTime = 0;
            while(sz--) {
                int node = q.front(); q.pop();
                maxTime = max(maxTime, time[node]);
                for(auto &it : adj[node]) {
                    indegree[it]--;
                    if(indegree[it] == 0) q.push(it);
                }
            }
            ans += maxTime;
        }
        return ans;
    }
};
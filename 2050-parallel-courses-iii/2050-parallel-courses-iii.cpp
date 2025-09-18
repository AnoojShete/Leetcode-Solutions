class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& edges, vector<int>& time) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        for(auto &e : edges) {
            int u = e[0] - 1, v = e[1] - 1;
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int> q;
        vector<int> finishTime(n);
        for(int i = 0; i < n; ++i) {
            if(indegree[i] == 0) {
                q.push(i);
                finishTime[i] = time[i];
            }
        }

        while(!q.empty()) {
            auto node = q.front(); q.pop();
            for(auto it : adj[node]) {
                finishTime[it] = max(finishTime[it], finishTime[node] + time[it]);
                if(--indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        return *max_element(finishTime.begin(), finishTime.end());
    }
};
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for(auto &e : times) {
            int u = e[0];
            int v = e[1];
            int time = e[2];
            adj[u].push_back({v, time});
        }
        vector<int> dijk(n + 1, INT_MAX);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        dijk[k] = 0;

        while(!pq.empty()) {
            auto p = pq.top(); pq.pop();
            int t = p.first;
            int node = p.second;
            for(auto it : adj[node]) {
                int neigh = it.first;
                int t2 = it.second;
                if(t + t2 < dijk[t2]) {
                    dijk[neigh] = t + t2;
                    pq.push({dijk[neigh], neigh});
                }
            }
        }
        
        int maxi = 0;
        for(int i = 1; i <= n; ++i) {
            if(dijk[i] == INT_MAX) return -1;
            maxi = max(maxi, dijk[i]);
        }

        return maxi;
    }
};
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> adj(n);
        for(int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0], v = edges[i][1];
            double p = succProb[i];
            adj[u].push_back({v, p});
            adj[v].push_back({u, p});
        }
        priority_queue<pair<double, int>> pq;
        vector<double> d(n, 0.0);
        d[start_node] = 1.0;
        pq.push({1.0, start_node});
        while(!pq.empty()) {
            auto [p, node] = pq.top(); pq.pop();
            if(node == end_node) return p;
            for(auto [nei, prob] : adj[node]) {
                double newProb = p * prob;
                if(newProb > d[nei]) {
                    d[nei] = newProb;
                    pq.push({newProb, nei});
                }
            }
        }
        return 0;
    }
};
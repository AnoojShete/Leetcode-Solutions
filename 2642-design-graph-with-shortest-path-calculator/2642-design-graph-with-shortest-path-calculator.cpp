class Graph {
private:
    vector<vector<pair<int, int>>> adj;
public:
    Graph(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        for(auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
        }
    }
    
    void addEdge(vector<int> e) {
        int u = e[0], v = e[1], w = e[2];
        adj[u].push_back({v, w});
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        int n = adj.size();
        vector<int> dist(n, INT_MAX);
        pq.push({0, node1});
        dist[node1] = 0;
        while(!pq.empty()) {
            auto [w, node] = pq.top(); pq.pop();
            if(node == node2) return w;
            if(dist[node] < w) continue;
            for(auto &[nei, wt] : adj[node]) {
                if(dist[nei] > w + wt) {
                    dist[nei] = w + wt;
                    pq.push({w+wt, nei});
                }
            }
        }
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
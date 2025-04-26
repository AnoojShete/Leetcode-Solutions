class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        // [wt, u, v]
        vector<pair<int, pair<int, int>>> edges;
        // Connecting all points with each other to get all edge wt possible
        for(int i = 0; i < n; ++i) {
            int x1 = points[i][0], y1 = points[i][1];
            for(int j = i + 1; j < n; ++j) {
                int x2 = points[j][0], y2 = points[j][1];
                // edge wt = |x1 - x2| + |y1 - y2| 
                int wt = abs(x1 - x2) + abs(y1 - y2);
                edges.push_back({wt, {i, j}});
            }
        }

        // Applying Kruskal's algorithm
        sort(edges.begin(), edges.end());
        DisjointSet ds(n);
        int mstCost = 0;
        for(auto &e : edges) {
            int wt = e.first;
            int u = e.second.first;
            int v = e.second.second;
            if(ds.findUPar(u) != ds.findUPar(v)) {
                mstCost += wt;
                ds.unionByRank(u, v);
            }
        }

        return mstCost;
    }
};
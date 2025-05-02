class DisjointSet {
public:
    vector<int> rank, parent;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = find(parent[node]);
    }
    
    void unionByRank(int u, int v) {
        int ulp_u = find(u);
        int ulp_v = find(v);
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
};

class Solution {
public:
    int intersect(const vector<int>& a, const vector<int>& b) {
        unordered_set<int> sa(a.begin(), a.end());
        int count = 0;
        for (int val : b) {
            if (sa.count(val)) {
                count++;
                sa.erase(val);
            }
        }
        return count;
    }
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n = properties.size();
        int m = properties[0].size();

        DisjointSet ds(n);

        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                if(intersect(properties[i], properties[j]) >= k) {
                    ds.unionByRank(i, j);
                }
            }
        }

        int components = 0;
        for(int i = 0; i < n; ++i) {
            if(ds.parent[i] == i) components++;
        }

        return components;
    }
};
class DSU {
public:
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int u) {
        if(parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }
    void unionBySize(int u, int v) {
        int root_u = find(u);
        int root_v = find(v);
        if(root_u == root_v) return;
        if(size[root_u] < size[root_v]) {
            parent[root_u] = root_v;
            size[root_v] += size[root_u];
        }
        else {
            parent[root_v] = root_u;
            size[root_u] += size[root_v];
        }
    }
};

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        DSU ds(n);
        for(auto &e : edges) {
            ds.unionBySize(e[0], e[1]);
        }
        vector<int> componentSizes;
        for(int i = 0; i < n; ++i) {
            if(ds.parent[i] == i) {
                componentSizes.push_back(ds.size[i]);
            }
        }

        long long ans = 0;
        long long sum = 0;
        for(auto sz : componentSizes) {
            ans += sum * sz;
            sum += sz;
        }

        return ans;
    }
};
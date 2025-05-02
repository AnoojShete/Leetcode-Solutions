class DSU {
public:
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 0);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int u) {
        if(parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }
    void unionBySize(int u, int v) {
        int root_u = find(u);
        int root_v = find(v);
        if(root_v == root_u) return;
        if(size[root_u] < size[root_v]) {
            size[root_v] += size[root_u];
            parent[root_u] = root_v;
        }
        else {
            size[root_u] += size[root_v];
            parent[root_v] = root_u;
        }
    }
};

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        DSU ds(n * m);
        unordered_map<int, vector<int>> rowMpp;
        unordered_map<int, vector<int>> colMpp;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(grid[i][j] == 0) continue;
                int node = i * m + j;
                rowMpp[i].push_back(node);
                colMpp[j].push_back(node);
            }
        }

        for(auto &[row, nodes] : rowMpp) {
            for(int i = 1; i < nodes.size(); ++i) {
                ds.unionBySize(nodes[0], nodes[i]);
            }
        }
        for(auto &[col, nodes] : colMpp) {
            for(int i = 1; i < nodes.size(); ++i) {
                ds.unionBySize(nodes[0], nodes[i]);
            }
        }
        
        unordered_map<int, int> mpp;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                int node = i * m + j;
                int root = ds.find(node);
                mpp[root]++;
            }
        }

        int count = 0;
        for(auto &[_, sz] : mpp) {
            if(sz >= 2) count += sz;
        }

        return count;
    }
};
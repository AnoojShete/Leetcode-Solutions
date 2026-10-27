class DSU {
    public:
    vector<int> size, parent;
    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        size.resize(n, 1);
    }
    int find(int u) {
        return u == parent[u] ? parent[u] : find(parent[u]);
    }
    void unite(int u, int v) {
        int rootu = find(u), rootv = find(v);
        if(rootu == rootv) return;
        if(size[rootu] < size[rootv]) swap(rootu, rootv);
        size[rootu] += size[rootv];
        parent[rootv] = rootu;
    }
};

class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int tot = m * n;
        DSU ds(tot);
        int delta[] = {-1, 0, 1, 0, -1};
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 0) continue;
                int node = i * n + j;
                for(int d = 0; d < 4; ++d) {
                    int ni = i + delta[d], nj = j + delta[d+1];
                    if(ni >= 0 && nj >= 0 && ni < m && nj < n && grid[ni][nj] != 0) {
                        ds.unite(node, ni * n + nj);
                    }
                }
            }
        }
        unordered_map<int, int> sum;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 0) continue;
                int node = i * n + j;
                sum[ds.find(node)] = (sum[ds.find(node)] + grid[i][j]) % k;
            }
        }
        int count = 0;
        for(auto [_, s] : sum) count += s % k == 0;
        return count;
    }
};
class DSU {
    public:
    vector<int> parent, size;
    vector<bool> flag;
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        iota(parent.begin(), parent.end(), 0);
        flag.resize(n, false);
    }
    int find(int u) {
        return parent[u] == u ? parent[u] : find(parent[u]);
    }
    void unite(int u, int v) {
        int rootu = find(u);
        int rootv = find(v);
        if(rootu == rootv) return;
        if(size[rootv] < size[rootu]) swap(rootu, rootv);
        size[rootv] += size[rootu];
        parent[rootu] = rootv;
        flag[rootv] = flag[rootu] || flag[rootv];
    }
};

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        DSU ds(m * n);
        int delta[] = {-1, 0, 1, 0, -1};
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 0 &&
                   (i == 0 || i == m-1 || j == 0 || j == n-1)) {
                    ds.flag[i * n + j] = true;
                }
            }
        }
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j]) continue;
                for(int k = 0; k < 4; ++k) {
                    int ni = i + delta[k], nj = j + delta[k + 1];
                    if(ni < m && nj < n && ni >= 0 && nj >= 0
                    && grid[ni][nj] == 0) {
                        ds.unite(i * n + j, ni * n + nj);
                    }
                }
            }
        }
        int totalIslands = 0, borderIslands = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j]) continue;
                int node = i * n + j;
                if(ds.find(node) == node) {
                    totalIslands++;
                    if(ds.flag[node]) borderIslands++;
                }
            }
        }
        return totalIslands - borderIslands;
    }
};
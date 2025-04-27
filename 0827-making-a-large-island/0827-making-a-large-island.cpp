class DisjointSet {
public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        iota(parent.begin(), parent.end(), 0);
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
    bool inBounds(int row, int col, int n) {
        return row >= 0 && col >= 0 && row < n && col < n;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);
        // vector<vector<bool>> vis(n, vector<bool>(n, false));
        for(int row = 0; row < n; ++row) {
            for(int col = 0; col < n; ++col) {
                if(grid[row][col] == 1) {
                    int node = row * n + col;
                    int delta[] = {-1, 0, 1, 0, -1};
                    for(int i = 0; i < 4; ++i) {
                        int nrow = row + delta[i];
                        int ncol = col + delta[i + 1]; 
                        if(inBounds(nrow, ncol, n) && grid[nrow][ncol] == 1) {
                            int adjNode = nrow * n + ncol;
                            if(ds.findUPar(node) != ds.findUPar(adjNode)) {
                                ds.unionBySize(node, adjNode);
                            }
                        }
                    }
                }
            }
        }
        // Changing 0 -> 1
        int maxArea = 0;
        for(int row = 0; row < n; ++row) {
            for(int col = 0; col < n; ++col) {
                
                set<int> st;
                if(grid[row][col] == 0) {
                    int node = row * n + col;
                    int delta[] = {-1, 0, 1, 0, -1};
                    for(int i = 0; i < 4; ++i) {
                        int nrow = row + delta[i];
                        int ncol = col + delta[i + 1];
                        if(inBounds(nrow, ncol, n) && grid[nrow][ncol] == 1) {
                            int adjNode = nrow * n + ncol;
                            st.insert(ds.findUPar(adjNode));
                        }
                    }
                    int area = 1;
                    for(auto it : st) {
                        area += ds.size[it];
                    }
                    maxArea = max(maxArea, area);
                }
            }
        }
        // Find max area without flipping any 0 
        // Test Case: 3
        for(int i = 0; i < n * n; ++i) {
            maxArea = max(maxArea, ds.size[ds.findUPar(i)]);
        }

        return maxArea;
    }
};
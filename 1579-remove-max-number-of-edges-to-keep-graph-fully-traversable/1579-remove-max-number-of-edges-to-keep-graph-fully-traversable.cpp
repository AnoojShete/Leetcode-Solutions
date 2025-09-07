class DSU {
    public:
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int u) {
        return u == parent[u] ? u : parent[u] = find(parent[u]);
    }
    void unite(int u, int v) {
        int rootu = find(u);
        int rootv = find(v);
        if(rootu == rootv) return;
        if(size[rootu] > size[rootv]) {
            parent[rootv] = rootu;
            size[rootu] += size[rootv];
        }
        else {
            parent[rootu] = rootv;
            size[rootv] += size[rootu];
        }
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU alice(n), bob(n);
        int extra = 0; // answer
        // Trying all type-3 edges
        for(auto &e : edges) {
            int u = e[1]-1, v = e[2]-1;
            if(e[0] == 3) {
                if(alice.find(u) == alice.find(v)) extra++;
                else {
                    alice.unite(u, v);
                    bob.unite(u, v);
                }
            }
        }
        for(auto &e : edges) {
            int type = e[0], u = e[1]-1, v = e[2]-1;
            if(type == 1) {
                if(alice.find(u) == alice.find(v)) extra++;
                else alice.unite(u, v);
            }
            else if(type == 2) {
                if(bob.find(u) == bob.find(v)) extra++;
                else bob.unite(u, v);
            }
        }
        int a = 0, b = 0;
        for(int i = 0; i < n; ++i) {
            if(alice.find(i) == i) a++;
            if(bob.find(i) == i) b++;
        }
        return a == 1 && b == 1 ? extra : -1;
    }
};
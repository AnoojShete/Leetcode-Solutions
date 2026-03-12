class DSU {
public:
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n+1);
        iota(parent.begin(), parent.end(), 0);
        size.resize(n+1, 1);
    }
    int find(int u) {
        return parent[u] = (u == parent[u] ? u : find(parent[u]));
    }
    bool unite(int u, int v) {
        int ru = find(u);
        int rv = find(v);
        if(ru == rv) return false;
        if(size[ru] < size[rv]) swap(ru, rv);
        parent[rv] = ru;
        size[ru] += size[rv];
        return true;
    }
};

class Solution {
public:
    bool isValid(int n, vector<vector<int>> &must, vector<vector<int>> &rest,
    int mid, int k) {
        DSU ds(n);
        int comp = n;

        for(auto &e : must) {
            int u = e[0], v = e[1], s = e[2];
            if(s < mid) return false;
            if(!ds.unite(u, v)) return false;
            comp--;
        }
        for(auto &e : rest) {
            int u = e[0], v = e[1], s = e[2];
            if(s >= mid) {
                if(ds.unite(u, v)) comp--;
            }
        }
        for(auto &e : rest) {
            int u = e[0], v = e[1], s = e[2];
            if(s < mid && s * 2 >= mid && ds.find(u) != ds.find(v)) {
                if(k == 0) continue;
                ds.unite(u, v);
                comp--;
                k--;
            }
        }
        return comp == 1;
    }
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        vector<vector<int>> must, rest;
        int high = 0;
        for(auto &e : edges) {
            int u = e[0], v = e[1], s = e[2], m = e[3];
            if(m) must.push_back({u, v, s});
            else rest.push_back({u, v, s});
            high = max(high, s * 2);
        }
        int low = 0;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(isValid(n, must, rest, mid, k))
                low = mid + 1;
            else
                high = mid - 1;
        }
        return high;
    }
};
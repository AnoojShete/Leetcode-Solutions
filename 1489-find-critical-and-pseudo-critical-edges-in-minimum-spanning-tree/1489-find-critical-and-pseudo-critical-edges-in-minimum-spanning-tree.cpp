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
    bool unite(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if(rootU == rootV) return false;
        if(size[rootU] > size[rootV]) {
            parent[rootV] = rootU;
            size[rootU] += size[rootV];
        }
        else {
            parent[rootU] = rootV;
            size[rootV] += size[rootU];
        }
        return true;
    }
};

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n,
    vector<vector<int>>& edges) {
        vector<pair<vector<int>, int>> indexedEdges;
        for(int i = 0; i < edges.size(); ++i) {
            indexedEdges.push_back({edges[i], i});
        }
        sort(indexedEdges.begin(), indexedEdges.end(), [](auto &a, auto &b) {
            return a.first[2] < b.first[2];
        });
        DSU ds(n);
        int mst = 0;
        for(auto &[e, _] : indexedEdges) {
            int u = e[0], v = e[1], w = e[2];
            if(ds.unite(u, v)) mst += w;
        }
        cout << mst << '\n';
        vector<vector<int>> ans(2);
        for(auto &[e, idx] : indexedEdges) {
            DSU ds(n);
            int newMst = 0;
            for(auto &[curr, _] : indexedEdges) {
                if(curr == e) continue;
                int u = curr[0], v = curr[1], w = curr[2];
                if(ds.unite(u, v)) newMst += w;
            }
            int components = 0;
            for(int i = 0; i < n; ++i) {
                if(ds.find(i) == i) components++;
            }
            if(components > 1 || newMst > mst) {
                ans[0].push_back(idx);
                continue;
            }
            DSU ds1(n);
            ds1.unite(e[0], e[1]); // forcing in MST
            int forcedMst = e[2];
            for(auto &[curr, _] : indexedEdges) {
                if(curr == e) continue;
                if(ds1.unite(curr[0], curr[1])) forcedMst += curr[2];
            }
            // cout << idx << " " << forcedMst << '\n';
            if(forcedMst == mst) ans[1].push_back(idx);
        }
        return ans;
    }
};
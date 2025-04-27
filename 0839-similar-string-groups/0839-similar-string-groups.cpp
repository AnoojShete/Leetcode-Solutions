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
    bool isSimilar(string s1, string s2) {
        int diff = 0;
        for(int i = 0; i < s1.length(); ++i) {
            if(s1[i] != s2[i]) diff++;
        }
        return diff <= 2;
    }
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        DisjointSet ds(n);
        int count = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                string s1 = strs[i];
                string s2 = strs[j];
                if(isSimilar(s1, s2)) {
                    if(ds.findUPar(i) != ds.findUPar(j)) {
                        count++;
                        ds.unionByRank(i, j);
                    }
                }
            }
        }
        return n - count;
    }
};
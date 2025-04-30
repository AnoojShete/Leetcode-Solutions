class DisjointSet {
public:
    vector<int> parent;
    DisjointSet(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = find(parent[node]);
    }
    void unionByLex(int u, int v) {
        int ulp_u = find(u);
        int ulp_v = find(v);
        if (ulp_u > ulp_v) parent[ulp_u] = ulp_v;
        else parent[ulp_v] = ulp_u;
    }
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DisjointSet ds(26);
        int n = s1.length();
        for(int i = 0; i < n; ++i) {
            ds.unionByLex(s1[i] - 'a', s2[i] - 'a');
        }
        string ans = "";
        for(auto ch : baseStr) {
            ans += (ds.find(ch-'a') + 'a');
        }

        return ans;
    }
};
class DSU {
    vector<int> size, parent;
public:
    DSU(int n) {
        size.resize(n+1, 1);
        parent.resize(n+1);
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
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1, 0);
        vector<int> candidate1, candidate2;
        for(auto &e : edges) {
            int u = e[0], v = e[1];
            if(parent[v] == 0) parent[v] = u;
            // 2 parent case
            else {
                // now we will have 2 candidate
                // because if there exist a cycle then 
                // we must remove the appopriate one to make it a tree
                candidate1 = {parent[v], v};
                candidate2 = {u, v};
                e[1] = 0; // Trick (explained later)
            }
        }
        // ****************************************************
        // Now checking if there exist a cycle
        // case1 : no cycle -> return candidate2 (since question asks to remove the later edges)
        // case2 : candidates were empty (meaning there is only a cycle) -> return cycle edge
        // case3 : if there exist a cycle and both 2 parent:
        // then it means the cycle edge might be creating 2 parent problem as well as a cycle. For that we have a trick..
        // Trick : while checking for 2parent -> mark the candidate2's e[1] = 0
        // so when detecting a cycle we skip whenever e[1] == 0 & if still the cycle exist then we know that candidate1 is the one creating the trouble otherwise return candidate2
        // ****************************************************
        DSU ds(n+1);
        for(auto &e : edges) {
            int u = e[0], v = e[1];
            if(v == 0) continue;
            // Cycle still exist after removing candidate2
            if(ds.find(u) == ds.find(v)) {
                // case 2: only cycle exist
                if(candidate1.empty()) return {u, v};
                // case 3:
                return candidate1;
            }
            else ds.unionBySize(u, v);
        }
        return candidate2;
    }
};
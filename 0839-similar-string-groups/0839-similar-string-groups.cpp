class Solution {
public:
    bool isSimilar(string &a, string &b) {
        int diff = 0;
        for(int i = 0; i < a.length(); ++i) {
            if(a[i] != b[i]) diff++;
            if(diff > 2) return false;
        }
        return true;
    }
    void dfs(string node, unordered_map<string, vector<string>> &adj, unordered_set<string> &vis) {
        vis.insert(node);
        for(auto it : adj[node]) {
            if(vis.find(it) == vis.end()) {
                dfs(it, adj, vis);
            }
        }
    }
    int numSimilarGroups(vector<string>& strs) {
        unordered_map<string, vector<string>> adj;
        int n = strs.size();
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                string u = strs[i], v = strs[j];
                if(isSimilar(u, v)) {
                    adj[u].push_back(v);
                    adj[v].push_back(u);
                }
            }
        }
        int component = 0;
        unordered_set<string> vis;
        for(auto node : strs) {
            if(vis.find(node) == vis.end()) {
                component++;
                dfs(node, adj, vis);
            }
        }

        return component;
    }
};
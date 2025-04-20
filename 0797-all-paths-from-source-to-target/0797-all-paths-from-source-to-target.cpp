class Solution {
public:
    void solve(int node, vector<vector<int>> &graph, vector<bool> &vis, 
    vector<vector<int>> &paths, vector<int> &temp, int target) {
        if(node == target) {
            paths.push_back(temp);
            vis = vector<bool>(graph.size(), false);
            return;
        }
        vis[node] = true;
        for(auto it :graph[node]) {
            if(!vis[it]) {
                temp.push_back(it);
                solve(it, graph, vis, paths, temp, target);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        int src = 0, target = n-1;
        vector<vector<int>> paths;
        vector<bool> vis(n, false);
        vector<int> temp = {0};
        solve(0, graph, vis, paths, temp, target);

        return paths;
    }
};
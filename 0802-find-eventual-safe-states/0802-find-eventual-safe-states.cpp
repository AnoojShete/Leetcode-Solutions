class Solution {
private:
    bool dfs(int node, vector<int> &visited, vector<int> &pathVisited,
    vector<int> &check, vector<vector<int>> &graph) {
        visited[node] = 1;
        pathVisited[node] = 1;
        check[node] = 0;
        for(auto &v : graph[node]) {
            if(!visited[v]) {
                if(dfs(v, visited, pathVisited, check, graph)) {
                    check[node] = 0;
                    return true;
                }
            }
            else if(pathVisited[v]) {
                check[node] = 0;
                return true;
            }
        }
        check[node] = 1;
        pathVisited[node] = 0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> visited(V, 0);
        vector<int> pathVisited(V, 0);
        vector<int> check(V, 0);
        vector<int> ans;
        for(int i = 0; i < V; ++i) {
            if(!visited[i]) {
                dfs(i, visited, pathVisited, check, graph);
            }
        }

        for(int i = 0; i < V; ++i) {
            if(check[i]) ans.push_back(i);
        }

        return ans;
    }
};
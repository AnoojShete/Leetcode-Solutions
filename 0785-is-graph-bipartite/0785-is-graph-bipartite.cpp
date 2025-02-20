class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);
        queue<int> q;

        for(int i = 0; i < V; i++) {
            if(color[i] == -1) {
                color[i] = 0;
                q.push(i);
                while(!q.empty()) {
                    int node = q.front();
                    q.pop();
                    for(auto it : graph[node]) {
                        if(color[it] == -1) {
                            color[it] = !color[node];
                            q.push(it);
                        }
                        else if(color[it] == color[node]) {
                            return false;
                        }
                    }
                }
            }

        }
        return true;
    }
};
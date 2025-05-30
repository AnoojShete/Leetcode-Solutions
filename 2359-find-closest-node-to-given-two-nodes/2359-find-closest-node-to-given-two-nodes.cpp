class Solution {
public:
    void dfs(int node, vector<int> &edges, 
    vector<bool> &vis, vector<int> &dist, int d) {
        vis[node] = true;
        dist[node] = d;
        if(edges[node] > 0 && !vis[edges[node]])
            dfs(edges[node], edges, vis, dist, d + 1);
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<bool> vis1(n);
        vector<bool> vis2(n);
        vector<int> dist1(n, -1);
        vector<int> dist2(n, -1);
        dfs(node1, edges, vis1, dist1, 0);
        dfs(node2, edges, vis2, dist2, 0);

        int minDist = INT_MAX;
        int node = -1;
        for(int i = 0; i < n; ++i) {
            if(dist1[i] != -1 && dist2[i] != -1) {
                int maxDist = max(dist1[i], dist2[i]);
                if(maxDist < minDist) {
                    minDist = maxDist;
                    node = i;
                }
            }
        }
        return node;
    }
};
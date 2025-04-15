class Solution {
public:
    void dfs(int node, vector<vector<int>> &rooms, vector<bool> &vis) {
        vis[node] = true;
        for(auto it : rooms[node]) {
            if(!vis[it]) {
                dfs(it, rooms, vis);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n, false);
        dfs(0, rooms, vis);

        for(auto it : vis) if(it == false) return false;

        return true;
    }
};
class Solution {
public:
    void dfs(int node, unordered_map<int,vector<int>> &adj, 
    unordered_map<int,bool> &vis){
        vis[node] = true;
        for(auto it : adj[node]){
            if(!vis[it]) dfs(it, adj, vis);
        }
    }
    int countComponents(vector<int>& nums, int threshold) {
        int n = nums.size();
        unordered_map<int,vector<int>> adj;
        for(auto i : nums){
           for(auto j = 2 * i; j <= threshold; j += i){
            adj[i].push_back(j);
            adj[j].push_back(i);
           }
        }
        unordered_map<int,bool> vis;
        int count=0;
        for(int i : nums){
            if(!vis[i]){
                count++;
                dfs(i,adj,vis);
            }
        }
        return count;
    }
};
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> mpp;
        for(int i = 0; i < n; ++i) mpp[arr[i]].push_back(i);
        queue<pair<int, int>> q;
        vector<bool> vis(n, false);
        q.push({0, 0});
        vis[0] = true;
        while(!q.empty()) {
            auto [idx, level] = q.front(); q.pop();
            if(idx == n-1) return level;
            if(idx > 0 && !vis[idx-1]) {
                q.push({idx-1, level + 1});
                vis[idx-1] = true;
            }
            if(idx < n-1 && !vis[idx+1]) {
                q.push({idx+1, level + 1});
                vis[idx+1] = true;
            }
            if(mpp.find(arr[idx]) != mpp.end()) {
                for(auto j : mpp[arr[idx]]) {
                    if(!vis[j]) {
                        q.push({j, level + 1});
                        vis[j] = true;
                    }
                }
                mpp.erase(arr[idx]);
            }
        }
        return -1;
    }
};
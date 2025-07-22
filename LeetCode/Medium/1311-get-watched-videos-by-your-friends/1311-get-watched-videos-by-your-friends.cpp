class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n = friends.size();
        queue<int> q;
        vector<bool> vis(n, false);
        q.push(id); vis[id] = true;
        while(!q.empty()) {
            int sz = q.size();
            if(!level) break;
            while(sz--) {
                int node = q.front(); q.pop();
                for(auto &nei : friends[node]) {
                    if(!vis[nei]) {
                        q.push(nei);
                        vis[nei] = true;
                    }
                }
            }
            level--;
        }
        unordered_map<string, int> mpp;
        while(!q.empty()) {
            int node = q.front(); q.pop();
            for(auto vid : watchedVideos[node]) mpp[vid]++;
        }
        vector<pair<string, int>> vidFreq(mpp.begin(), mpp.end());
        sort(vidFreq.begin(), vidFreq.end(), [](auto &a, auto &b) {
            if(a.second == b.second) return a.first < b.first;
            return a.second < b.second;
        });
        vector<string> ans;
        for(auto &[vid, f] : vidFreq) {
            ans.push_back(vid);
        }
        return ans;
    }
};
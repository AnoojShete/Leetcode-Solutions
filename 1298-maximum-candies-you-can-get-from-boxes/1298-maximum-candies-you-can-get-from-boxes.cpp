class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        queue<int> q;
        vector<bool> vis(n, false); // box visited but closed
        for(auto box : initialBoxes) {
            if(status[box]) q.push(box);
            else vis[box] = true;
        }
        int count = 0;
        while(!q.empty()) {
            int box = q.front(); q.pop();
            count += candies[box];
            for(auto &it : keys[box]) {
                if(!status[it] && vis[it]) {
                    q.push(it); // push the prev box which was closed (since now key is found)
                }
                status[it] = 1;
            }
            for(auto &it : containedBoxes[box]) {
                if(status[it]) q.push(it);
                else vis[it] = true;
            }
        }

        return count;
    }
};
class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        queue<int> q;
        vector<int> canOpen;
        for(auto box : initialBoxes) {
            q.push(box);
            canOpen.push_back(box);
        }
        while(!q.empty()) {
            int box = q.front(); q.pop();
            for(auto it : containedBoxes[box]) {
                canOpen.push_back(it);
            }
        }
    }
};
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int time = 0;
        int maxi = neededTime[0];
        for(int i = 1; i < colors.size(); ++i) {
            if(colors[i] == colors[i-1]) {
                time += min(maxi, neededTime[i]);
            }
            else maxi = neededTime[i];
        }
        return time;
    }
};
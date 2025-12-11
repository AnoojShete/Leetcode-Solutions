class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int> xMin(n+1, INT_MAX), xMax(n+1, INT_MIN), yMin(n+1, INT_MAX), yMax(n+1, INT_MIN);
        for(auto &building : buildings) {
            int x = building[0], y = building[1];
            xMin[y]=min(xMin[y], x);
            xMax[y]=max(xMax[y], x);
            yMin[x]=min(yMin[x], y);
            yMax[x]=max(yMax[x], y);
        }
        int count = 0;
        for(auto &building : buildings) {
            int x = building[0], y = building[1];
            count += (xMin[y] < x && xMax[y] > x && yMin[x] < y && yMax[x] > y);
        }
        return count;
    }
};
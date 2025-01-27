class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans = 1;
        int n = points.size();

        for(int i = 0; i < n; i++) {
            map<double, int> mpp;
            for(int j = i+1; j < n; j++) {
                double dy = (double)(points[j][1] - points[i][1]);
                double dx = (double)(points[j][0] - points[i][0]);
                double x = dy / dx;
                if(dy < 0 && dx == 0) {
                    mpp[abs(x)]++;
                }
                else mpp[x]++;
            }
            int temp = 0;
            for(auto p : mpp) {
                temp = max(temp, p.second + 1);
            }
            ans = max(temp, ans);
        }
        return ans;
    }
};
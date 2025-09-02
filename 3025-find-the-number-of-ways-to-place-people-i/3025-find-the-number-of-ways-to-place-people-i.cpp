class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end(), [](auto &a, auto &b) {
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        int count = 0;
        for(int i = 0; i < n; ++i) {
            vector<int> first = points[i];
            int x1 = first[0], y1 = first[1];
            for(int j = i + 1; j < n; ++j) {
                vector<int> second = points[j];
                int x2 = second[0], y2 = second[1];
                if(y2 > y1) continue;
                bool flag = false;
                for(int k = i+1; k < j; ++k) {
                    if(x1 <= points[k][0] && points[k][0] <= x2 
                    && y1 >= points[k][1] && points[k][1] >= y2) {
                        flag = true;
                        break;
                    }
                }
                if(!flag) count++;
            }
        }
        return count;
    }
};
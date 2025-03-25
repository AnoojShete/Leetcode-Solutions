typedef vector<int> vi;

class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rect) {
        sort(rect.begin(), rect.end(), [](vi &a, vi &b) {return a[0] == b[0] ? a[2] < b[2] : a[0] < b[0];});
        int end_x = rect[0][2];
        int count_x = 0;
        for(int i = 1; i < rect.size(); ++i) {
            if(rect[i][0] > rect[i - 1][2]) count_x++;
        }
        sort(rect.begin(), rect.end(), [](vi &a, vi &b) {return a[1] == b[1] ? a[3] < b[3] : a[1] < b[1];});
        int end_y = rect[0][3];
        int count_y = 0;
        for(int i = 1; i < rect.size(); ++i) {
            if(rect[i][1] > rect[i - 1][3]) count_y++;
        }

        return count_x >= 2 || count_y >= 2;
    }
};
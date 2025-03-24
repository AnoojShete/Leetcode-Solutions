class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        vector<vector<int>> ans;
        int n = meetings.size();

        sort(meetings.begin(), meetings.end());
        for(int i = 0; i < n; i++) {
            if(ans.empty() || meetings[i][0] > ans.back()[1]) {
                ans.push_back(meetings[i]);
            }
            else {
                ans.back()[1] = max(ans.back()[1], meetings[i][1]);
            }
        }

        int count = 0;
        if(ans[0][0] != 1) count += ans[0][0] - 1;
        for(int i = 1; i < ans.size(); ++i) {
            int st = ans[i][0], st_prev = ans[i - 1][0];
            int end = ans[i][1], end_prev = ans[i - 1][1];
            if(end_prev + 1 != st) {
                count += st - end_prev - 1;
            }
        }
        count += days - ans.back()[1];
        return count;
    }
};
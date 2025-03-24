class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = meetings.size();
        sort(meetings.begin(), meetings.end());

        int count = meetings[0][0] - 1;
        int prevEnd = meetings[0][1];

        for(int i = 1; i < n; ++i) {
            int st = meetings[i][0];
            int end = meetings[i][1];
            if(st > prevEnd) {
                count += st - prevEnd - 1;
            }
            prevEnd = max(end, prevEnd);
        }

        return count;
    }
};
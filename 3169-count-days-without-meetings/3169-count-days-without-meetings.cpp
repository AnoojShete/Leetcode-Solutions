class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = meetings.size();
        sort(meetings.begin(), meetings.end());

        int count = 0;
        int curStart = -1, curEnd = -1;
        for(auto &meeting : meetings) {
            int start = meeting[0], end = meeting[1];
            if(start > curEnd) {
                if(curEnd != -1) {
                    count += curEnd - curStart + 1;
                }
                curStart = start;
                curEnd = end;
            }
            else {
                curEnd = max(curEnd, end);
            }
        }
        if(curEnd != -1) {
            count += curEnd - curStart + 1;
        }

        return days - count;
    }
};
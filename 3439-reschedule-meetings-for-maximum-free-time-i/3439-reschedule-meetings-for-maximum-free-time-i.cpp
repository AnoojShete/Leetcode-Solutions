class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> freeTime;

        freeTime.push_back(startTime[0]);;
        for(int i = 1; i < n; ++i) {
            freeTime.push_back(startTime[i] - endTime[i-1]);
        }
        freeTime.push_back(eventTime-endTime[n-1]);

        int windowTime = 0;
        for(int i = 0; i <= k && i < freeTime.size(); ++i) {
            windowTime += freeTime[i];
        }
        int maxi = windowTime;
        for(int i = k + 1; i < freeTime.size(); ++i) {
            windowTime += freeTime[i] - freeTime[i - (k + 1)];
            maxi = max(maxi, windowTime);
        }
        return maxi;
    }
};
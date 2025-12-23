class Solution {
public:
    vector<vector<int>> dp;

    int binarySearch(vector<vector<int>> &events, int idx, int endTime) {
        int low = idx, high = events.size();
        while (low < high) {
            int mid = (low + high) / 2;
            if (events[mid][0] > endTime)
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }

    int solve(int idx, int k, vector<vector<int>> &events) {
        if (idx == events.size() || k == 0) return 0;
        if (dp[idx][k] != -1) return dp[idx][k];

        // Option 1: Skip current event
        int notTake = solve(idx + 1, k, events);

        // Option 2: Take current event
        int nextIdx = binarySearch(events, idx + 1, events[idx][1]);
        int take = events[idx][2] + solve(nextIdx, k - 1, events);

        return dp[idx][k] = max(take, notTake);
    }

    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        dp.resize(events.size(), vector<int>(2 + 1, -1));
        return solve(0, 2, events);
    }
};

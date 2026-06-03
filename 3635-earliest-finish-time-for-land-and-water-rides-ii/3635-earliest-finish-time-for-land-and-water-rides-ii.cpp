# define all(a) a.begin(), a.end()

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        auto solve = [&](vector<int> &firstStart, vector<int> &firstDuration,
                        vector<int> &secondStart, vector<int> &secondDuration) {
            int m = firstStart.size(), n = secondStart.size();
            vector<pair<int, int>> secondIdx;
            for(int i = 0; i < n; ++i)
                secondIdx.push_back({secondStart[i], secondDuration[i]});
            sort(all(secondIdx));
            vector<int> pre(n), suff(n);
            pre[0] = secondIdx[0].second;
            for(int i = 1; i < n; ++i) {
                pre[i] = min(pre[i-1], secondIdx[i].second);
            }
            suff[n-1] = secondIdx[n-1].first + secondIdx[n-1].second;
            for(int i = n-2; i >= 0; --i) {
                suff[i] = min(suff[i+1], secondIdx[i].first + secondIdx[i].second);
            }
            int ans = INT_MAX;
            for(int i = 0; i < m; ++i) {
                int start = firstStart[i], duration = firstDuration[i];
                int time = start + duration;
                int pos = upper_bound(all(secondIdx), time,
                [](int val, pair<int, int> &p) {
                    return val < p.first;
                }) - secondIdx.begin() - 1;
                if(pos >= 0) ans = min(ans, time + pre[pos]);
                if(pos + 1 < n) ans = min(ans, suff[pos + 1]);
            }
            return ans;
        };
        return min(solve(landStartTime, landDuration, waterStartTime, waterDuration), solve(waterStartTime, waterDuration, landStartTime, landDuration));
    }
};
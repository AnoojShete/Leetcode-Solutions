#define all(a) a.begin(), a.end()

class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        using T = tuple<int, int, int, int>;
        vector<T> sortedIntervals;
        for(int i = 0; i < n; ++i) {
            int l = intervals[i][0], r = intervals[i][1], w = intervals[i][2];
            sortedIntervals.push_back({l, r, w, i});
        }
        sort(all(sortedIntervals));

        vector<vector<pair<long long, vector<int>>>> memo(n, vector<pair<long long, vector<int>>>(5));
        vector<vector<bool>> vis(n, vector<bool>(5, false));

        function<pair<long long, vector<int>>(int, int)> solve = [&](int idx, int k) -> pair<long long, vector<int>> {
            if(idx == n || k == 0) return {0, {}};
            if(vis[idx][k]) return memo[idx][k];
            auto skip = solve(idx + 1, k);
            int r = get<1>(sortedIntervals[idx]);
            int next = upper_bound(sortedIntervals.begin(), sortedIntervals.end(), r,
                [](int value, const T& interval) {
                    return value < get<0>(interval);
                }) - sortedIntervals.begin();
            auto take = solve(next, k - 1);
            take.first += get<2>(sortedIntervals[idx]);
            take.second.push_back(get<3>(sortedIntervals[idx]));
            sort(all(take.second));
            vis[idx][k] = true;
            if(take.first > skip.first) return memo[idx][k] = take;
            else if(skip.first > take.first) return memo[idx][k] = skip;
            return memo[idx][k] = min(take, skip);
        };

        vector<int> ans = solve(0, 4).second;
        sort(all(ans));
        return ans;
    }
};
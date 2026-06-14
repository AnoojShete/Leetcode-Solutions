class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int, int>> v;
        for(int i = 0; i < n; ++i) v.push_back({intervals[i][0], i});
        sort(v.begin(), v.end());
        vector<int> ans;
        for(auto interval : intervals) {
            int end = interval[1];
            auto it = lower_bound(v.begin(), v.end(), make_pair(end, -1));
            if(it != v.end()) ans.push_back(it->second);
            else ans.push_back(-1);
        }
        return ans;
    }
};
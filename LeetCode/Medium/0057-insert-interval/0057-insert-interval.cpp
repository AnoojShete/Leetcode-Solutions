class Solution {
public:
    int bs(vector<vector<int>> &intervals, int val, bool flag) {
        int low = 0, high = intervals.size()-1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(flag) {
                if(intervals[mid][1] >= val) high = mid - 1;
                else low = mid + 1;
            }
            else {
                if(intervals[mid][0] <= val) low = mid + 1;
                else high = mid - 1;
            }
        }
        return flag ? low : high;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.empty()) return {newInterval};
        int newStart = newInterval[0], newEnd = newInterval[1];
        int startIdx = bs(intervals, newStart, true);
        int endIdx = bs(intervals, newEnd, false);
        vector<vector<int>> ans;
        
        // NO OVERLAP
        if(startIdx > endIdx) {
            ans.insert(ans.end(), intervals.begin(), intervals.begin() + startIdx);
            ans.push_back(newInterval);
            ans.insert(ans.end(), intervals.begin() + endIdx + 1, intervals.end());
            return ans;
        }
        
        // YES OVERLAP
        ans.insert(ans.end(), intervals.begin(), intervals.begin() + startIdx);
        int mergeStart = min(newStart, intervals[startIdx][0]);
        int mergeEnd = max(newEnd, intervals[endIdx][1]);
        ans.push_back({mergeStart, mergeEnd});
        ans.insert(ans.end(), intervals.begin() + endIdx + 1, intervals.end());
        return ans;
    }
};
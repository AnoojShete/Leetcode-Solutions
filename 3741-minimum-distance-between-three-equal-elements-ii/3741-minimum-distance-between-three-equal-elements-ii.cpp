class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, deque<int>> mpp;
        int ans = INT_MAX;
        for(int i = 0; i < nums.size(); ++i) {
            mpp[nums[i]].push_back(i);
            if(mpp[nums[i]].size() > 3) mpp[nums[i]].pop_front();
            if(mpp[nums[i]].size() == 3) {
                int f = mpp[nums[i]][0], s = mpp[nums[i]][2];
                ans = min(ans, 2*(s-f));
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
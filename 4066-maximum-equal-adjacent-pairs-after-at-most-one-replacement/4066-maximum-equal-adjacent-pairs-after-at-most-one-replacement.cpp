class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int n = nums.size();
        map<pair<int, int>, int> mpp;
        int count = 0;
        for(int i = 1; i < n; ++i) {
            if(nums[i] == nums[i-1]) {count++; continue;}
            pair<int, int> p = {min(nums[i], nums[i-1]), max(nums[i], nums[i-1])};
            mpp[p]++;
        }
        int ans = count;
        for(auto [_, x] : mpp) ans = max(ans, count + x);
        return ans;
    }
};
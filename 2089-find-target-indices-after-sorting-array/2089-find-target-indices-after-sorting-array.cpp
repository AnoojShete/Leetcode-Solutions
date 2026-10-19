#define all(a) a.begin(), a.end()

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(all(nums));
        int i = lower_bound(all(nums), target) - nums.begin(); 
        int j = upper_bound(all(nums), target) - nums.begin();
        vector<int> ans(j - i);
        iota(all(ans), i);
        return ans;
    }
};
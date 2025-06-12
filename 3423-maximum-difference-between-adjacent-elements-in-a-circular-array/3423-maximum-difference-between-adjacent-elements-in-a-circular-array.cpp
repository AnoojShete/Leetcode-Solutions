class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxDiff = INT_MIN;
        for(int i = 0; i < nums.size(); ++i) {
            maxDiff = max(maxDiff, abs(nums[i] - nums[(i + 1) % nums.size()]));
        }
        return maxDiff;
    }
};
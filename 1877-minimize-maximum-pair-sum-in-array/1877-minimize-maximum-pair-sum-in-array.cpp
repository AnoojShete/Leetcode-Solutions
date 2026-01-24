class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxi = 0;
        for(int i = 0; i < nums.size(); ++i) {
            maxi = max(maxi, nums[i] + nums[nums.size() - 1 - i]);
        }
        return maxi;
    }
};
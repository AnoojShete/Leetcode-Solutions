class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long ans = 1;
        int count = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(ans * nums[i] > 0 || (i + 1 < nums.size() && nums[i + 1] < 0)) {
                ans *= nums[i];
                count++;
            }
        }

        return ans;
    }
};
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mpp;
        int ans = 0;
        int i = 0, j = 0;
        for(auto num : nums) {
            while(j < n && nums[j] <= num + k) {
                mpp[nums[j]]++;
                j++;
            }
            while(i < n && nums[i] < num - k) {
                mpp[nums[i]]--;
                i++;
            }
            ans = max(ans, min(j - i, numOperations + mpp[num]));
        }
        i = 0;
        for(int j = 0; j < n; ++j) {
            while(nums[i] + k + k < nums[j]) ++i;
            ans = max(ans, min(j-i+1, numOperations));
        }
        return ans;
    }
};
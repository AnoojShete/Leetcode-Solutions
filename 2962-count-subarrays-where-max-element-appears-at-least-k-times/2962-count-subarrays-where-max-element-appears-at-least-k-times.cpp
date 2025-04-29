class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxElement = *max_element(nums.begin(), nums.end());
        int count = 0;
        long long ans = 0;
        for(int i = 0, j = 0; i < nums.size(); ++i) {
            if(nums[i] == maxElement) count++;
            while(j < nums.size() && count >= k) {
                ans += nums.size() - i;
                if(nums[j] == maxElement) count--;
                j++;
            }
        }
        return ans;
    }
};
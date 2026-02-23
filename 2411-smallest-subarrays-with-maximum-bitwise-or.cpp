class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> last(30);
        vector<int> ans(n);
        for(int i = n-1; i >= 0; --i) {
            for(int j = 0; j < 30; ++j) {
                if(nums[i] & (1 << j)) last[j] = i;
            }
            ans[i] = max(1,  *max_element(begin(last), end(last)) - i + 1);
        }
        return ans;
    }
};
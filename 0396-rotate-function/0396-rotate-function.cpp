class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int sum = 0, init = 0;
        for(int i = 0; i < n; ++i) {
            sum += nums[i];
            init += i * nums[i];
        }
        int ans = init;
        for(int i = 1; i < n; ++i) {
            init += sum - n * nums[n-i];
            ans = max(ans, init);
        }
        return ans;
    }
};
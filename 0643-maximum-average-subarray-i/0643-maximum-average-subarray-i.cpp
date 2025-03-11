class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;
        double ans = 0.0;
        for(int i = 0; i < k; ++i) {
            sum += nums[i];
        }
        ans = sum;
        for(int r = k; r < nums.size(); ++r) {
            sum += nums[r] - nums[r - k];
            ans = max(ans, sum);
        }

        return ans / k;
    }
};
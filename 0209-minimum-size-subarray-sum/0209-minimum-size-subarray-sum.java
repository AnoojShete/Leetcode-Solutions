class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int n = nums.length;
        int ans = Integer.MAX_VALUE;
        int l = 0;
        int sum = 0;
        for(int r = 0; r < n; ++r) {
            sum += nums[r];
            while(sum >= target) {
                ans = Math.min(ans, r - l + 1);
                // Remove leftmost element of the window from sum
                sum -= nums[l];
                // To find smaller valid subarray
                l++;
            }
        }
        // edge case -> if summation(array) < target
        if(ans == Integer.MAX_VALUE) return 0;
        return ans;
    }
}
var maxSubArray = function(nums) {
    const n = nums.length;
    const dp = new Array(n).fill(0);
    dp[0] = nums[0];
    for(let i = 1; i < n; ++i) {
        dp[i] = Math.max(nums[i], nums[i] + dp[i-1]);
    }
    return Math.max(...dp);
};
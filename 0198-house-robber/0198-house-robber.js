var rob = function(nums) {
    const n = nums.length;
    const dp = new Array(n+2);
    dp[n] = 0;
    dp[n-1] = nums[n-1];
    for(let i = n-2; i >= 0; --i) {
        dp[i] = Math.max(dp[i+1], nums[i] + dp[i+2]);
    }
    return dp[0];
};
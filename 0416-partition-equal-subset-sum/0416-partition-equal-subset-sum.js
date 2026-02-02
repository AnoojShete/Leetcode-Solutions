var canPartition = function(nums) {
    const n = nums.length;
    const sum = nums.reduce((a, b)=>a+b, 0);
    if(sum & 1) return false;
    const target = sum / 2;
    // dp[i][x] = T/F, i = idx, x = sum
    const dp = Array.from({ length: n }, () =>
    Array.from({ length: target + 1 }, () => false));
    for(let i = 0; i < n; ++i) dp[i][0] = true;
    if(nums[0] <= target) dp[0][nums[0]] = true;
    for(let i = 1; i < n; ++i) {
        for(let j = 0; j <= target; ++j) {
            dp[i][j] = dp[i-1][j] || (j >= nums[i] && dp[i-1][j-nums[i]]);
        }
    }
    return dp[n-1][target];
};
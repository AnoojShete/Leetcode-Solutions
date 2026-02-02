function solve(idx, prevIdx, nums, dp) {
    if(idx == nums.length) return 0;
    if(dp[idx][prevIdx + 1] != -1) return dp[idx][prevIdx + 1];
    let take = 0, skip;
    if(prevIdx === -1 || nums[prevIdx] < nums[idx]) take = 1 + solve(idx + 1, idx, nums, dp);
    skip = solve(idx + 1, prevIdx, nums, dp);
    return dp[idx][prevIdx + 1] = Math.max(take, skip);
}

var lengthOfLIS = function(nums) {
    const n = nums.length;
    const dp = Array.from({ length: n }, () => Array.from({ length: n+1 }, ()=>-1));
    return solve(0, -1, nums, dp);
};
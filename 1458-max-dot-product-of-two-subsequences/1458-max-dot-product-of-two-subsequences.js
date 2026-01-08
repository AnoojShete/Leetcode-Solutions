var maxDotProduct = function(nums1, nums2) {
    const m = nums1.length, n = nums2.length;
    const dp = Array.from({length: m + 1}, () => Array(n + 1).fill(-Infinity));
    for(let i = m-1; i >= 0; --i) {
        for(let j = n-1; j >= 0; --j) {
            let take = nums1[i] * nums2[j];
            take += Math.max(0, dp[i+1][j+1]);
            let skip = Math.max(dp[i+1][j], dp[i][j+1]);
            dp[i][j] = Math.max(take, skip);
        }
    }
    return dp[0][0];
};
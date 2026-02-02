var numSquares = function(n) {
    // dp[x] = minimum no. of perfect sq. to sum to x
    const dp = new Array(n+1).fill(Infinity);
    dp[0] = 0;
    for(let i = 1; i <= n; ++i) {
        for(let j = 1; j * j <= i; ++j) {
            const psq = j*j;
            dp[i] = Math.min(1 + dp[i - psq], dp[i]);
        }
    }
    return dp[n];
};
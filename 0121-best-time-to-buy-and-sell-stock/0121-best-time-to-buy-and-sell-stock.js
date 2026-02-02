var maxProfit = function(prices) {
    const n = prices.length;
    const dp = new Array(n);
    // dp[i] = maximum profit if sold on ith day
    dp[0] = 0;
    let mini = Infinity;
    for(let i = 1; i < n; ++i) {
        dp[i] = Math.max(dp[i-1], prices[i] - mini);
        mini = Math.min(mini, prices[i]);
    }
    return Math.max(...dp);
};
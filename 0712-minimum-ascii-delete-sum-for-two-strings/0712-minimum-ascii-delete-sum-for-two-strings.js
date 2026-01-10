function lcs_ascii(s1, s2) {
    const m = s1.length, n = s2.length;
    const dp = Array.from({ length: m + 1 }, () => new Int32Array(n + 1));
    for (let i = 1; i <= m; i++) {
        const a = s1.charCodeAt(i - 1);
        for (let j = 1; j <= n; j++) {
            if (s1[i - 1] === s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + a;
            } else {
                dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n]
}

var minimumDeleteSum = function(s1, s2) {
    let s1_sum = 0, s2_sum = 0;
    for(const ch of s1) {
        s1_sum += ch.charCodeAt(0);
    }
    for(const ch of s2) {
        s2_sum += ch.charCodeAt(0);
    }
    return s1_sum + s2_sum - 2 * lcs_ascii(s1, s2);
};
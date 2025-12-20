/**
 * @param {string} text1
 * @param {string} text2
 * @return {number}
 */
var longestCommonSubsequence = function(text1, text2) {
    const m = text1.length, n = text2.length;
    const t = Array.from({length:m+1}, ()=>Array(n+1).fill(0));
    for(let i = 1; i <= m; ++i) {
        for(let j = 1; j <= n; ++j) {
            if(text1[i-1] == text2[j-1]) {
                t[i][j] = 1 + t[i-1][j-1];
            }
            else {
                t[i][j] = Math.max(t[i-1][j], t[i][j-1]);
            }
        }
    }
    return t[m][n];
};
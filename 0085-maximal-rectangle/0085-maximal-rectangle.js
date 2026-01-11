var maximalRectangle = function(matrix) {
    if (!matrix.length) return 0;
    const m = matrix.length, n = matrix[0].length;
    dp = new Array(n).fill(0);
    let ans = 0;
    for(let row = 0; row < m; ++row) {
        for(let col = 0; col < n; ++col) {
            dp[col] = matrix[row][col] === '1' ? dp[col] + 1 : 0;
        }
        let st = [];
        const left = new Array(n), right = new Array(n);
        for(let i = 0; i < n; ++i) {
            while(st.length > 0 && dp[st[st.length-1]] >= dp[i]) st.pop();
            left[i] = st.length ? st[st.length-1] : 0;
            st.push(i);
        }
        st = [];
        for(let i = n-1; i >= 0; --i) {
            while(st.length > 0 && dp[st[st.length-1]] >= dp[i]) st.pop();
            right[i] = st.length ? st[st.length-1] : n;
            st.push(i);
        }
        for(let i = 0; i < n; ++i) {
            ans = Math.max(ans, (right[i] - left[i]) * dp[i]);
        }
    }
    return ans;
};
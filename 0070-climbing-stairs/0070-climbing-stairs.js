var climbStairs = function(n) {
    let prev1 = 1, prev2 = 1;
    for(let i = 2; i <= n; ++i) {
        let curr = prev1 + prev2;
        prev1 = prev2;
        prev2 = curr;
    }
    return prev2;
};
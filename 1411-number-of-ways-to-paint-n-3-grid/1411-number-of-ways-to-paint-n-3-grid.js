var numOfWays = function(n) {
    const MOD = 1000000007;
    const dp = Array.from({ length: n },() =>
        Array.from({ length: 3 },() =>
            Array.from({ length: 3 },() =>
                Array(3).fill(0)
            )
        )
    );

    for(let c0 = 0; c0 < 3; c0++) {
        for(let c1 = 0; c1 < 3; c1++) {
            for(let c2 = 0; c2 < 3; c2++) {
                if(c0 !== c1 && c1 !== c2) {
                    dp[0][c0][c1][c2] = 1;
                }
            }
        }
    }

    for(let r = 1; r < n; r++) {
        for(let c0 = 0; c0 < 3; c0++) {
            for(let c1 = 0; c1 < 3; c1++) {
                for(let c2 = 0; c2 < 3; c2++) {
                    if(c0 === c1 || c1 === c2) continue;
                    let ways = 0;
                    for(let p0 = 0; p0 < 3; p0++) {
                        for(let p1 = 0; p1 < 3; p1++) {
                            for(let p2 = 0; p2 < 3; p2++) {
                                if(
                                    c0 !== p0 &&
                                    c1 !== p1 &&
                                    c2 !== p2
                                ) {
                                    ways =(ways + dp[r - 1][p0][p1][p2]) % MOD;
                                }

                            }
                        }
                    }

                    dp[r][c0][c1][c2] = ways;
                }
            }
        }
    }

    let ans = 0;
    for(let c0 = 0; c0 < 3; c0++) {
        for(let c1 = 0; c1 < 3; c1++) {
            for(let c2 = 0; c2 < 3; c2++) {
                ans =(ans + dp[n - 1][c0][c1][c2]) % MOD;
            }
        }
    }

    return ans;
};
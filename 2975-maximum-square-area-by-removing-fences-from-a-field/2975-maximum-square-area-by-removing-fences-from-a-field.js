var maximizeSquareArea = function(m, n, hFences, vFences) {
    hFences.push(m);
    vFences.push(n);
    const hsz = hFences.length, vsz = vFences.length;
    const st = new Set();
    for(let i = 0; i < hsz - 1; ++i) {
        for(let j = i + 1; j < hsz; ++j) {
            st.add(Math.abs(hFences[j] - hFences[i]));
        }
    }

    let maxLen = 0n;
    for(let i = 0; i < vsz - 1; ++i) {
        for(let j = i + 1; j < vsz; ++j) {
            const len = Math.abs(vFences[j] - vFences[i]);
            if(st.has(len)) {
                if(BigInt(len) > maxLen) {
                    maxLen = BigInt(len);
                }
            }
        }
    }
    const MOD = 1000000007n;
    return maxLen == 0 ? -1 : Number((maxLen * maxLen) % MOD);
};
var maximizeSquareArea = function(m, n, hFences, vFences) {
    hFences.push(1, m);
    vFences.push(1, n);
    const hsz = hFences.length, vsz = vFences.length;
    const hst = new Set(), vst = new Set();
    for(let i = 0; i < hsz - 1; ++i) {
        for(let j = i + 1; j < hsz; ++j) {
            hst.add(Math.abs(hFences[j] - hFences[i]));
        }
    }
    for(let i = 0; i < vsz - 1; ++i) {
        for(let j = i + 1; j < vsz; ++j) {
            vst.add(Math.abs(vFences[j] - vFences[i]));
        }
    }
    let maxLen = 0n;

    for(const len of vst) {
        if(hst.has(len)) {
            if(BigInt(len) > maxLen) maxLen = BigInt(len);
        }
    }
    const MOD = 1000000007n;
    return maxLen == 0 ? -1 : Number((maxLen * maxLen) % MOD);
};
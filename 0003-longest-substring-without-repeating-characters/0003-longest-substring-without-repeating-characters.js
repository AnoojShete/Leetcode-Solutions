/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    const n = s.length;
    const mpp = new Map();
    let i = 0;
    let len = 0;
    for(let j = 0; j < n; ++j) {
        mpp.set(s[j], (mpp.get(s[j]) || 0) + 1);
        while (mpp.get(s[j]) > 1) {
            if (mpp.get(s[i]) === 1) {
                mpp.delete(s[i]);
            } else {
                mpp.set(s[i], mpp.get(s[i]) - 1);
            }
            i++;
        }
        len = Math.max(len, j - i + 1);
    }
    return len;
};
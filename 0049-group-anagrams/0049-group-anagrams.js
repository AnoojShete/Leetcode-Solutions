var groupAnagrams = function(strs) {
    const mpp = new Map();
    for(const str of strs) {
        const temp = str.split('').sort().join('');
        if(!mpp.has(temp)) {
            mpp.set(temp, []);
        }
        mpp.get(temp).push(str);
    }
    return Array.from(mpp.values());
};
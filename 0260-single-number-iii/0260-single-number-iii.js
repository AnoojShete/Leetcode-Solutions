var singleNumber = function(nums) {
    let xor = 0;
    for(const num of nums) {
        xor ^= num;
    }
    const diff = xor & (-xor);
    const ans = new Array(2).fill(0);
    for(const num of nums) {
        if((num & diff) === 0) ans[0] ^= num;
        else ans[1] ^= num;
    }
    return ans;
};
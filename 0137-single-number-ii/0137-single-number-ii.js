var singleNumber = function(nums) {
    let ans = 0;
    for(let i = 0; i <= 31; ++i) {
        let count = 0;
        for(const num of nums) {
            count += (num >> i) & 1;
        }
        count %= 3;
        ans |= (count << i);
    }
    return ans;
};
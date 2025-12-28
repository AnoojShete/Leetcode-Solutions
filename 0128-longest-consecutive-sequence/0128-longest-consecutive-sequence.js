var longestConsecutive = function(nums) {
    if(!nums.length) return 0;
    nums.sort((a, b)=>a-b);
    let ans = 1, count = 1;
    for(let i = 1; i < nums.length; ++i) {
        if(nums[i] === nums[i-1]) continue;
        if(nums[i] === nums[i-1] + 1) count++;
        else count = 1;
        ans = Math.max(ans, count);
    }
    return ans;
};
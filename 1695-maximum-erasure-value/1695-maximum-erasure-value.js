/**
 * @param {number[]} nums
 * @return {number}
 */
var maximumUniqueSubarray = function(nums) {
    let mpp = new Map();
    let sum = 0;
    let ans = 0;
    let i = 0;
    for(let j = 0; j < nums.length; ++j) {
        sum += nums[j];
        mpp.set(nums[j], (mpp.get(nums[j]) || 0) + 1);
        while(mpp.get(nums[j]) > 1) {
            sum -= nums[i];
            mpp.set(nums[i], mpp.get(nums[i]) - 1);
            i++;
        }
        ans = Math.max(ans, sum);
    }
    return ans;
};
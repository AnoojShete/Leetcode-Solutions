/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function(nums) {
    const mpp = new Map();
    for(let num of nums) {
        if(mpp.get(num) != undefined) return true;
        mpp.set(num, mpp.get(num) + 1);
    }
    return false;
};
var isTrionic = function(nums) {
    let h = 0, v = 0;
    for(let i = 1; i < nums.length; ++i) {
        if(nums[i-1] == nums[i] || nums[i] == nums[i+1]) return false;
        if(nums[i-1] < nums[i] && nums[i] > nums[i+1]) h++;
        else if(nums[i-1] > nums[i] && nums[i] < nums[i+1]) {
            if(!h) return false;
            v++;
        }
        if(h > 1 || v > 1) return false;
    }
    return h == 1 && v == 1;
};
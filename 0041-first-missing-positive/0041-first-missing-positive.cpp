class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map<int, int> mpp;
        int small = nums[0], large = nums[0];
        for(auto num : nums) {
            if(num < small) small = num;
            if(num > large) large = num;
            mpp[num]++;
        }
        for(int i = 1; i <= INT_MAX; i++) {
            if(!mpp.count(i) && i > 0) return i;
        }
        return i + 1;
    }
};
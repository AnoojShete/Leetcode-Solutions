class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        int evenSum = 0, oddSum = 0;
        for(int i = 0; i < n; ++i) {
            if(i & 1) oddSum += nums[i];
            else evenSum += nums[i];
        }
        int count = 0;
        int left_even = 0, left_odd = 0;
        for(int i = 0; i < n; ++i) {
            if(i & 1) {
                oddSum -= nums[i];
                if(left_even + oddSum == left_odd + evenSum) count++;
                left_odd += nums[i];
            }
            else {
                evenSum -= nums[i];
                if(left_odd + evenSum == left_even + oddSum) count++;
                left_even += nums[i];
            }
        }
        return count;
    }
};
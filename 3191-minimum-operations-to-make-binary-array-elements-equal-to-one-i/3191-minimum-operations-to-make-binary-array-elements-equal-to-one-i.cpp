class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i = 0; i < n - 2; ++i) {
            if(nums[i] == 0) {
                nums[i] = !nums[i];
                nums[i + 1] = !nums[i + 1];
                nums[i + 2] = !nums[i + 2];
                count++;
            }
        }

        // Note -> any valid solution must leave the last two elements as 1s.
        return (nums[n - 2] == 1 && nums[n - 1] == 1) ? count : -1;
    }
};
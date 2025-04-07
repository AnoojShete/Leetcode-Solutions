class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2 != 0) return false;

        int target = total / 2;
        sort(nums.begin(), nums.end(), greater<int>()); // Helps prune faster

        return backtrack(nums, 0, target);
    }

    bool backtrack(vector<int>& nums, int index, int target) {
        if (target == 0) return true;
        if (target < 0 || index >= nums.size()) return false;

        // Choose the number at current index
        if (backtrack(nums, index + 1, target - nums[index])) return true;

        // Skip the number
        return backtrack(nums, index + 1, target);
    }
};

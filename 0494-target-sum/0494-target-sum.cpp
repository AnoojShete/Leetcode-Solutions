class Solution {
public:
    int solve(int idx, vector<int> &nums, int target, int sum, vector<vector<int>> &memo) {
        if(idx == nums.size()) {
            return sum == target ? 1 : 0;
        }
        // to avoid negative indexing we shift sum by 1000
        if(memo[idx][sum + 1000] != -1) return memo[idx][sum + 1000];

        int count = 0;
        count += solve(idx + 1, nums, target, sum + nums[idx], memo);
        count += solve(idx + 1, nums, target, sum - nums[idx], memo);

        memo[idx][sum + 1000] = count;
        return count;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<vector<int>> memo(nums.size(), vector<int>(2002, -1));
        return solve(0, nums, target, 0, memo);
    }
};
class Solution {
public:
    bool solve(int idx, vector<int> &nums, int sum, int totalSum, vector<vector<int>> &memo) {
        if(idx == nums.size()) {
            return sum == totalSum - sum;
        }
        if(memo[idx][sum] != -1) return memo[idx][sum];
        return memo[idx][sum] = (solve(idx + 1, nums, sum + nums[idx], totalSum, memo)
                || solve(idx + 1, nums, sum, totalSum, memo));
    }
    bool canPartition(vector<int>& nums) {
        vector<vector<int>> memo(201, vector<int>(20001, -1));
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        return solve(0, nums, 0, totalSum, memo);
    }
};
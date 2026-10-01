class Solution {
public:
    int memo[2501][2501];
    int solve(int idx, int prev, int prevIdx, vector<int> &nums) {
        if(idx == nums.size()) return 0;
        if(memo[idx][prevIdx + 1] != -1) return memo[idx][prevIdx + 1];
        int take = 0, dontTake = 0;
        if(prevIdx == -1 || prev < nums[idx]) {
            take = 1 + solve(idx + 1, nums[idx], idx, nums);
        }
        dontTake = solve(idx + 1, prev, prevIdx, nums);

        return memo[idx][prevIdx + 1] = max(take, dontTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(memo, -1, sizeof memo);
        return solve(0, INT_MIN, -1, nums);
    }
};
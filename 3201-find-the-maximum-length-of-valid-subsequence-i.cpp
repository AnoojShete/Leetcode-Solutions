class Solution {
public:
    int solve(int idx, vector<int>& nums, int flag,
              vector<vector<int>>& memo) {
        if (idx == nums.size())
            return 0;
        if (memo[idx][flag] != -1)
            return memo[idx][flag];
        int take = 0, dontTake;
        if (nums[idx] % 2 == flag)
            take = 1 + solve(idx + 1, nums, !(nums[idx] % 2), memo);
        dontTake = solve(idx + 1, nums, flag, memo);
        return memo[idx][flag] = max(take, dontTake);
    }
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> memo(n + 1, vector<int>(2, -1));
        int even = 0, odd = 0;
        for(auto it : nums) even += !(it%2), odd += it%2;
        cout << even << " " << odd;
        return max({solve(0, nums, 0, memo), solve(0, nums, 1, memo), even, odd});
    }
};
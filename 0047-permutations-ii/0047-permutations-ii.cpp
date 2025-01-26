class Solution {
public:
    void solve(vector<int> &nums, int l, int r, set<vector<int>> &ans) {
        if(l == r) {
            ans.insert(nums);
            return;
        }
        for(int i = l; i <= r; i++) {
            swap(nums[l], nums[i]);
            solve(nums, l+1, r, ans);
            swap(nums[l], nums[i]);
        }
        return;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> ans;
        solve(nums, 0, nums.size()-1, ans);
        vector<vector<int>> res(ans.begin(), ans.end());
        return res;
    }
};
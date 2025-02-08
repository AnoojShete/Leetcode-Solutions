class Solution {
public:
    void solve(vector<int> &nums, vector<int> &temp, int index, vector<vector<int>> &ans) {
        ans.push_back(temp);
        for(int i = index; i < nums.size(); i++) {
            if(i > index && nums[i] == nums[i - 1]) continue;
            temp.push_back(nums[i]);
            solve(nums, temp, i+1, ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(nums, temp, 0, ans);

        return ans;
    }
};
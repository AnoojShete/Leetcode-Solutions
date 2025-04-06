class Solution {
public:
    void solve(int index, vector<int> &temp, int prev, vector<int> &nums, vector<int> &ans) {
        if(index >= nums.size()) {
            if(temp.size() > ans.size()) {
                ans = temp;
                
            }
            return;
        }
        if(nums[index] % prev == 0) {
            temp.push_back(nums[index]);
            solve(index + 1, temp, nums[index], nums, ans);
            temp.pop_back();
        }
        solve(index + 1, temp, prev, nums, ans);
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        vector<int> temp;
        solve(0, temp, 1, nums, ans);

        return ans;
    }
};
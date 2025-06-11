class Solution {
public:
    void solve(int idx, vector<int> &nums, vector<int> &temp, set<vector<int>> &st, vector<vector<int>> &ans) {
        if(idx == nums.size()) {
            if(temp.size() > 1 && st.find(temp) == st.end()){
                ans.push_back(temp);
                st.insert(temp);
            }
            return;
        }
        if(temp.empty() || temp.back() <= nums[idx]) temp.push_back(nums[idx]);
        solve(idx + 1, nums, temp, st, ans);
        if(!temp.empty()) temp.pop_back();
        solve(idx + 1, nums, temp, st, ans);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        set<vector<int>> st;
        solve(0, nums, temp, st, ans);
        return ans;
    }
};
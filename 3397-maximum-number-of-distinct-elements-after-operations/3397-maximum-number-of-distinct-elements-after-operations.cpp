class Solution {
public:
    int solve(int idx, vector<int> &nums, int k, unordered_set<int> &st) {
        if(idx == nums.size()) return st.size();
        int ans = 0;
        for(int i = -k; i <= k; ++i) {
            st.insert(nums[idx]+i);
            ans = max(ans, solve(idx + 1, nums, k, st));
            st.erase(nums[idx]+i);
        }
        return ans;
    }
    int maxDistinctElements(vector<int>& nums, int k) {
        unordered_set<int> st;
        return solve(0, nums, k, st)+1;
    }
};
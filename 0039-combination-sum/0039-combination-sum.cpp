class Solution {
public:
    void solve(vector<int> &candidates, int target, vector<int> &temp, int sum, int index, vector<vector<int>> &ans) {
        if(sum > target) return;
        if(sum == target) {
            ans.push_back(temp);
            return;
        }
        for(int i = index; i < candidates.size(); i++) {
            temp.push_back(candidates[i]);
            sum += candidates[i];
            solve(candidates, target, temp, sum, i, ans);
            temp.pop_back();
            sum -= candidates[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(candidates, target, temp, 0, 0, ans);

        return ans;
    }
};
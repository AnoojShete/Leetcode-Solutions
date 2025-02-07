class Solution {
public:
    void solve(vector<int> &candidates, vector<int> &temp, int target, int sum, int index, vector<vector<int>> &ans) {
        if(sum > target) return;
        if(sum == target) {
            ans.push_back(temp);
            return;
        }
        for(int i = index; i < candidates.size(); i++) {
            if(i != index && candidates[i] == candidates[i-1]) continue;
            sum += candidates[i];
            temp.push_back(candidates[i]);
            solve(candidates, temp, target, sum, i + 1, ans);
            temp.pop_back();
            sum -= candidates[i];
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        solve(candidates, temp, target, 0, 0, ans);

        return ans;
    }
};
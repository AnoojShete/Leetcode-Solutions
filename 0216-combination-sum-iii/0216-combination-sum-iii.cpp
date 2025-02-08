class Solution {
public: 
    void solve(int k, int n, vector<int> &temp, vector<vector<int>> &ans, int sum, int start) {
        if(sum == n && temp.size() == k) {
            ans.push_back(temp);
            return;
        }
        if(sum > n) return;
        for(int i = start; i < 10; i++) {
            if(!temp.empty() && temp.back() == i) continue;
            sum += i;
            temp.push_back(i);
            solve(k, n, temp, ans, sum, i + 1);
            temp.pop_back();
            sum -= i;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(k, n, temp, ans, 0, 1);

        return ans;
    }
};
class Solution {
public:
    void solve(int n, int k, vector<int> &temp, vector<vector<int>> &ans, int start) {
        if(k == 0) {
            ans.push_back(temp);
            return;
        }
        for(int i = start; i <= n; i++) {
            temp.push_back(i);
            solve(n, k-1, temp, ans, i + 1);
            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(n, k, temp, ans, 1);

        return ans;
    }
};
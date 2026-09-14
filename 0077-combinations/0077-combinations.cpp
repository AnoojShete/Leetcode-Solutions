class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        function<void(int, int)> solve = [&](int i, int j) -> void {
            if(i > n || j == 0) {
                if(j == 0) ans.push_back(temp);
                return;
            }
            temp.push_back(i);
            solve(i + 1, j - 1);
            temp.pop_back();
            solve(i + 1, j);
        };
        solve(1, k);
        return ans;
    }
};
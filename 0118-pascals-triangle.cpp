class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        for(int i = 0; i < n; ++i) {
            vector<int> temp;
            for(int j = 0; j <= i; ++j) {
                if(j == 0 || j == i) temp.push_back(1);
                else {
                    int val = ans[i-1][j-1]+ans[i-1][j];
                    temp.push_back(val);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
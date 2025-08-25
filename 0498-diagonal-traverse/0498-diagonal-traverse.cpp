class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> ans;
        bool flag = true; // up
        int i = 0, j = 0;
        while(i < m && j < n) {
            ans.push_back(mat[i][j]);
            if((flag && i == 0 && j < n - 1)
            || (!flag && j == 0 && j == m - 1)
            || (!flag && i == m - 1 && j < m - 1)) {
                flag = !flag, j++;
                if(i < m && j < n) ans.push_back(mat[i][j]);
            }
            if((flag && i == 0 && j == n - 1)
            || (flag && j == n - 1 && i < m - 1)
            || (!flag && j == 0 && i < m - 1)) {
                flag = !flag, i++;
                if(i < m && j < n) ans.push_back(mat[i][j]);
            }
            if(flag) i--, j++;
            else i++, j--;
        }
        return ans;
    }
};
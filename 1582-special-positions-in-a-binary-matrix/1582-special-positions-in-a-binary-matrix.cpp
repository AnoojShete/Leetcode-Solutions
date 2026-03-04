class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> countRow(m), countCol(n);
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                countRow[i] += mat[i][j];
                countCol[j] += mat[i][j];
            }
        }
        int count = 0;
        for(int i = 0; i < m; ++i) {
            if(countRow[i] > 1) continue;
            for(int j = 0; j < n; ++j) {
                if(countCol[j] > 1) continue;
                if(mat[i][j]) count++;
            }
        }
        return count;
    }
};
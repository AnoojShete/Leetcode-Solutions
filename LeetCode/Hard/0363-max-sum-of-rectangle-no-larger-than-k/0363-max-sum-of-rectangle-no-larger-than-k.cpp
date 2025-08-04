class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> prefix(m, vector<int>(n, 0));
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                prefix[i][j] = mat[i][j];
                if(i > 0) prefix[i][j] += prefix[i-1][j];
                if(j > 0) prefix[i][j] += prefix[i][j-1];
                if(i > 0 && j > 0) prefix[i][j] -= prefix[i-1][j-1];
            }
        }
        int maxSum = INT_MIN;
        for(int r1 = 0; r1 < m; ++r1) {
            for(int c1 = 0; c1 < n; ++c1) {
                for(int r2 = r1; r2 < m; ++r2) {
                    for(int c2 = c1; c2 < n; ++c2) {
                        int sum = prefix[r2][c2];
                        if(r1 > 0) sum -= prefix[r1-1][c2];
                        if(c1 > 0) sum -= prefix[r2][c1-1];
                        if(r1 > 0 && c1 > 0) sum += prefix[r1-1][c1-1];
                        if(sum > maxSum && sum <= k) maxSum = sum;
                    }
                }
            }
        }
        return maxSum;
    }
};
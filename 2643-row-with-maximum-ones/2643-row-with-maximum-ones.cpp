class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int sum = 0;
        int maxi = 0;
        int index = 0;
        int numOnes = 0;
        for(int i = 0; i < n; i++) {
            sum = 0;
            for(int j = 0; j < m; j++) {
                sum += mat[i][j];
            }
            if(sum > maxi) {
                index = i;
                numOnes = sum;
                maxi = sum;
            }
        }

        return {index, numOnes};
    }
};
class Solution {
public:
    int memo[51][51];
    int solve(vector<int> &values, int i, int j) {
        if(i >= j) return 0;
        if(memo[i][j] != -1) return memo[i][j];
        int ans = INT_MAX;
        for(int k = i; k < j; ++k) {
            int temp = values[i-1]*values[k]*values[j] + solve(values, i, k) + solve(values, k + 1, j);
            ans = min(ans, temp);
        }
        return memo[i][j] = ans;
    }
    int minScoreTriangulation(vector<int>& values) {
        memset(memo, -1, sizeof memo);
        int n = values.size();
        return solve(values, 1, n-1);
    }
};
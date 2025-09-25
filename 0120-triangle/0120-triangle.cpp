class Solution {
public:
    int memo[201][201];
    int solve(int i, int j, vector<vector<int>> &triangle) {
        int n = triangle.size();
        if(i == n) return 0;
        if(i == n-1) return triangle[i][j];
        if(memo[i][j] != -1) return memo[i][j];
        return memo[i][j] = triangle[i][j] + min(solve(i+1, j, triangle), solve(i+1, j+1, triangle));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        memset(memo, -1, sizeof memo);
        return solve(0, 0, triangle);
    }
};
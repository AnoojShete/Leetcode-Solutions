class Solution {
public:
    int memo[20];
    int solve(int n) {
        if(n <= 1) return 1;
        if(memo[n] != -1) return memo[n];
        int count = 0;
        for(int i = 0; i < n; ++i)
            count += solve(i) * solve(n-i-1);
        return memo[n] = count;
    }
    int numTrees(int n) {
        memset(memo, -1, sizeof memo);
        return solve(n);
    }
};
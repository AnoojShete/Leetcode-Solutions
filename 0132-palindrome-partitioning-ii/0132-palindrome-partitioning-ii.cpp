class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> cut(n+1, 0);
        for (int i = 0; i <= n; i++) cut[i] = i-1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; i-j >= 0 && i+j < n && s[i-j]==s[i+j] ; j++)
                cut[i+j+1] = min(cut[i+j+1],1+cut[i-j]);

            for (int j = 1; i-j+1 >= 0 && i+j < n && s[i-j+1] == s[i+j]; j++)
                cut[i+j+1] = min(cut[i+j+1],1+cut[i-j+1]);
        }
        return cut[n];
    }
};

/*
My Solution TLE:
DP Bottom Up
// User function Template for C++

class Solution {
  public:
    int memo[1001][1001];
    bool isPalindrome(string &s, int i, int j) {
        if(i > j) return false;
        while(i < j) {
            if(s[i] != s[j]) return false;
            i++, j--;
        }
        return true;
    }
    int solve(string &s, int i, int j) {
        if(i >= j) return 0;
        if(isPalindrome(s, i, j)) return 0;
        if(memo[i][j] != -1) return memo[i][j];
        int ans = INT_MAX;
        for(int k = i; k < j; ++k) {
            int left, right;
            if(memo[i][k] != -1) {
                left = memo[i][k];
            }
            else {
                memo[i][k] = left = solve(s, i, k);
            }
            if(memo[k+1][j] != -1) {
                right = memo[k+1][j];
            }
            else {
                memo[k+1][j] = right = solve(s, k+1, j);
            }
            int temp = left + right + 1;
            ans = min(ans, temp);
        }
        return memo[i][j] = ans;
    }
    int minCut(string &s) {
        int n = s.length();
        memset(memo, -1, sizeof memo);
        return solve(s, 0, n-1);
    }
};
*/
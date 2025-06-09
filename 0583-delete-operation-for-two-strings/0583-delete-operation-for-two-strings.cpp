class Solution {
public:
    int minDistance(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        int t[m+1][n+1];
        for(int i = 0; i <= m; ++i) t[i][0] = 0;
        for(int i = 0; i <= n; ++i) t[0][i] = 0;
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(s1[i-1] == s2[j-1]) t[i][j] = 1 + t[i-1][j-1];
                else t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
        return m + n - 2 * t[m][n];
    }
};
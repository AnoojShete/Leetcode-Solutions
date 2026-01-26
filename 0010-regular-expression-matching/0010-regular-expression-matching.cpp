class Solution {
public:
    bool solve(int i, int j, string &s, string &p) {
        if(j == p.length()) return i == s.length();
        
        bool flag = (i < s.length() && (s[i] == p[j] || p[j] == '.'));
        if(j + 1 < p.length() && p[j + 1] == '*') {
            return solve(i, j + 2, s, p) || (flag && solve(i + 1, j, s, p));
        }
        return flag && solve(i + 1, j + 1, s, p);
    }
    bool isMatch(string s, string p) {
        return solve(0, 0, s, p);
    }
};
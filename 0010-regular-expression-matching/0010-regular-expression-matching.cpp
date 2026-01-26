class Solution {
public:
    bool solve(int i, int j, string &s, string &p) {
        if(j == p.length()) return i == s.length();

        if(j < p.length() - 1 && p[j + 1] == '*') {
            bool take = false;
            if(i < s.length() && (s[i] == p[j] || p[j] == '.')) take = solve(i + 1, j, s, p);
            bool skip = solve(i, j + 2, s, p);
            return take || skip;
        }

        return (s[i] == p[j] || p[j] == '.') && solve(i + 1, j + 1, s, p);
    }
    bool isMatch(string s, string p) {
        return solve(0, 0, s, p);
    }
};
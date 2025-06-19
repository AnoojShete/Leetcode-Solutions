class Solution {
public:
    unordered_map<string, bool> memo;
    bool solve(string s1, string s2) {
        if(s1 == s2) return true;
        if(s1.length() <= 1) return false;
        string key = s1 + "|" + s2;
        if(memo.find(key) != memo.end()) return memo[key];
        int n = s1.length();
        for(int i = 1; i < n; ++i) {
            // Without swap
            if (solve(s1.substr(0, i), s2.substr(0, i)) &&
                solve(s1.substr(i), s2.substr(i)))
                return memo[key] = true;
            // With swap
            if (solve(s1.substr(0, i), s2.substr(n - i)) &&
                solve(s1.substr(i), s2.substr(0, n - i)))
                return memo[key] = true;
        }

        return memo[key] = false;
    }
    bool isScramble(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        if(n1 != n2) return false;
        if(!n1 && !n2) return true;
        return solve(s1, s2);
    }
};
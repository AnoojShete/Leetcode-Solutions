class Solution {
private:
    bool isPalindrome(string &s) {
        int len = s.length();
        int l = 0, r = len - 1;
        while(l < r) {
            if(s[l] != s[r]) return false;
            l++, r--;
        }

        return true;
    }
public:
    string longestPalindrome(string s) {
        // if(s.length() == 1) return s;
        string ans = "";
        int maxLen = 0;
        for(int i = 0; i < s.size(); ++i) {
            for(int j = i; j < s.size(); ++j) {
                string pal = s.substr(i, j - i + 1);
                if(isPalindrome(pal)) {
                    if(pal.size() > maxLen) {
                        ans = pal;
                        maxLen = pal.size();
                    }
                }
            }
        }
        return ans;
    }
};
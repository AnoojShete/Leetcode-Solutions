class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.length();
        if(numRows == 1 || len <= 2) return s;
        int step1, step2;
        string ans = "";
        for(int i = 0; i < numRows; ++i) {
            step1 = (numRows - i - 1) * 2;
            step2 = i * 2;
            int pos = i;
            if(pos < len) {
                ans += s[pos];
            }
            while(true) {
                pos += step1;
                if(pos >= len) break;
                if(step1) ans += s[pos];

                pos += step2;
                if(pos >= len) break;
                if(step2) ans += s[pos];
            }
        }
        return ans;
    }
};
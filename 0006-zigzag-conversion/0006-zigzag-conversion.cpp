class Solution {
public:
    string convert(string s, int numRows) {
        if(s.size() <= 2) return s;

        string ans = "";
        int diff = numRows * 2 - 2;
        int j = 0;
        while(j < s.size()) {
            ans += s[j];
            j += diff;
        }
        for(int i = 1; i < numRows - 1; ++i) {
            j = i;
            int k = 0;
            while(j < s.size()) {
                ans += s[j];
                int jump = (numRows - i) * 2 - 2;
                if(k % 2 == 0) {
                    j += jump;
                }
                else j += diff - jump;
                ++k;
            }   
        }
        j = numRows - 1;
        while(j < s.size()) {
            ans += s[j];
            j += diff;
        }

        return ans;
    }
};
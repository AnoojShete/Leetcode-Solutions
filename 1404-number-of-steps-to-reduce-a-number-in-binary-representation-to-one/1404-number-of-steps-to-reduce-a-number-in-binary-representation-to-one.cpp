class Solution {
public:
    int numSteps(string s) {
        int count = 0;
        while(s.length() > 1) {
            if(s.back() - '0') {
                int idx = s.length() - 1;
                while(idx >= 0 && s[idx] != '0') {
                    s[idx] = '0';
                    idx--;
                }
                if(idx < 0) s = '1' + s;
                else s[idx] = '1';
            }
            else s.pop_back();
            count++;
        }
        return count;
    }
};
class Solution {
public:
    int myAtoi(string s) {
        long long ans = 0;
        bool sign = true; // true -> pos, false ->neg
        bool isLeading = true;
        bool isStart = false;
        for(int i = 0; i < s.size(); ++i) {
            if(!isalpha(s[i])) {
                if(s[i] == '.') break;
                if(s[i] == ' ') {
                    if(isStart) break;
                    continue;
                }
                if(s[i] == '0' && isLeading) {
                    isStart = true;
                    continue;
                }
                if(s[i] == '+') {
                    if(isStart) break;
                    isStart = true;
                    continue;
                }
                if(s[i] == '-') {
                    if(isStart) break;
                    sign = false;
                    isStart = true;
                    continue;
                }
                isLeading = false;
                isStart = true;
                ans = ans * 10 + s[i] - '0';
            }
            else break;
        }
        ans = sign ? ans : -1 * ans;
        if(ans > INT_MAX) return INT_MAX;
        if(ans < INT_MIN) return INT_MIN;
        return (int)ans;
    }
};
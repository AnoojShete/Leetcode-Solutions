class Solution {
public:
    bool judgeCircle(string moves) {
        int c1 = 0, c2 = 0;
        for(auto ch : moves) {
            if(ch == 'L') c1++;
            else if(ch == 'R') c1--;
            else if(ch == 'U') c2++;
            else c2--;
        }
        return c1 == 0 && c2 == 0;
    }
};
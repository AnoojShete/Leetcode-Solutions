class Solution {
public:
    bool judgeCircle(string moves) {
        int c1 = 0, c2 = 0;
        for(auto ch : moves) {
            switch(ch) {
                case 'R':
                    c1++;
                    break;
                case 'L':
                    c1--;
                    break;
                case 'U':
                    c2++;
                    break;
                case 'D':
                    c2--;
                    break;
            }
        }
        return c1 == 0 && c2 == 0;
    }
};
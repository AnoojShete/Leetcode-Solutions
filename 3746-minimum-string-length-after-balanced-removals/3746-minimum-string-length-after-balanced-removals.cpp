class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int a = 0, b = 0;
        for(auto ch : s) a += (ch == 'a'), b += (ch == 'b');
        return abs(a - b);
    }
};
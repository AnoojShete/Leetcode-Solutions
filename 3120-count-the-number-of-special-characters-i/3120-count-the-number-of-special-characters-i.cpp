class Solution {
public:
    int numberOfSpecialChars(string word) {
        int a = 0, b = 0;
        for(auto ch : word) {
            if(islower(ch)) a |= (1 << ch-'a');
            else b |= (1 << ch-'A');
        }
        return __builtin_popcount(a & b);
    }
};
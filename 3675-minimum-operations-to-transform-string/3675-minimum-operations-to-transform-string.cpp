class Solution {
public:
    int minOperations(string s) {
        int op = 0;
        for(auto ch : s) {
            int count = (26 - (ch - 'a')) % 26;
            op = max(op, count);
        }
        return op;
    }
};
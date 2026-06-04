class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int count = 0;
        for(int num = num1; num <= num2; ++num) {
            string s = to_string(num);
            for(int i = 1; i < s.length() - 1; ++i) {
                if((s[i-1] < s[i] && s[i] > s[i+1])
                || (s[i-1] > s[i] && s[i] < s[i+1])) count++;
            }
        }
        return count;
    }
};
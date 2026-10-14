class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(9*num < sum) return "";
        string ans;
        for(int i = 0; i < num; ++i) {
            int digit = 9;
            while(digit > sum) {
                digit--;
            }
            sum -= digit;
            ans.push_back('0'+digit);
        }
        return ans;
    }
};
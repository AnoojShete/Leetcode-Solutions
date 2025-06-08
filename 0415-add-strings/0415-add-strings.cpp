class Solution {
public:
    string addStrings(string num1, string num2) {
        string sum = "";
        int carry = 0;
        int n1 = num1.length(), n2 = num2.length();
        int i;
        for(i = 0; i < min(n1, n2); ++i) {
            int x = num1[n1-i-1] - '0';
            int y = num2[n2-i-1] - '0';
            int add = (x + y + carry) % 10;
            sum = char(add + '0') + sum;
            carry = (x + y) / 10;
        }
        while(i < n1) {
            int x = num1[n1 - i - 1] - '0';
            int add = (x + carry) % 10;
            sum = char(add + '0') + sum;
            carry = (x + carry > 9) ? 1 : 0;
            i++;
        }
        
        while(i < n2) {
            int x = num2[n2 - i - 1] - '0';
            int add = (x + carry) % 10;
            sum = char(add + '0') + sum;
            carry = (x + carry > 9) ? 1 : 0;
            i++;
        }
        if(carry) sum = '1' + sum;
        return sum;
    }
};
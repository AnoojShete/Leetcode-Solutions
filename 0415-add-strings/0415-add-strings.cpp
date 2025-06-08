class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1 = num1.size(), n2 = num2.size();
        int i = 0;
        string sum = "";
        int carry = 0;
        while(i < n1 || i < n2 || carry) {
            int x = (i < n1) ? num1[n1 - i - 1] - '0' : 0;
            int y = (i < n2) ? num2[n2 - i - 1] - '0' : 0;
            int add = (x + y + carry) % 10;
            sum = char(add + '0') + sum;
            carry = (carry + x + y) / 10;
            i++;
        }
        return sum;
    }
};
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        int m = num1.length(), n = num2.length();
        vector<string> v;
        int maxSize = 0;
        for(int j = n-1; j >= 0; --j) {
            int carry = 0;
            string temp;

            int shift = n - 1 - j;
            temp.append(shift, '0');
            for(int i = m-1; i >= 0; --i) {
                int sum = carry + (num1[i] - '0') * (num2[j] - '0');
                carry = sum / 10;
                temp.push_back('0' + (sum % 10));
            }
            if(carry) temp.push_back('0' + carry);
            maxSize = max(maxSize, (int)temp.length());
            v.push_back(temp);
        }
        string ans;
        int carry = 0;
        for(int i = 0; i < maxSize || carry; ++i) {
            int sum = carry;
            for(auto num : v) {
                if(i < num.size()) {
                    sum += num[i] - '0';
                }
            }
            ans.push_back((sum % 10) + '0');
            carry = sum / 10;
        }
        while(ans.size() > 1 && ans.back() == '0') ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

        string ans;

        if ((numerator < 0) ^ (denominator < 0)) ans.push_back('-');

        long long num = llabs((long long)numerator);
        long long den = llabs((long long)denominator);

        ans += to_string(num / den);
        long long rem = num % den;

        if (rem == 0) return ans;

        ans.push_back('.');

        unordered_map<long long, int> remPos;
        while (rem != 0) {
            if (remPos.find(rem) != remPos.end()) {
                ans.insert(remPos[rem], "(");
                ans.push_back(')');
                break;
            }

            remPos[rem] = ans.size();
            rem *= 10;
            ans += to_string(rem / den);
            rem %= den;
        }

        return ans;
    }
};

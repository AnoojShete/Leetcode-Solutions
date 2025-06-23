typedef long long ll;

class Solution {
public:
    bool isPalindrome(const string &s) {
        int l = 0, r = s.length()-1;
        while(l < r) {
            if(s[l] != s[r]) return false;
            l++, r--;
        }
        return true;
    }
    string toBaseK(ll num, int k) {
        string s;
        while(num > 0) {
            s += char('0' + num % k);
            num /= k;
        }
        reverse(s.begin(), s.end());
        return s;
    }
    vector<ll> generatePalindromes(int digits) {
        vector<ll> res;
        int halfLen = (digits + 1) / 2;
        int start = (digits == 1) ? 1 : pow(10, halfLen - 1);
        int end = pow(10, halfLen) - 1;
        for (int i = start; i <= end; ++i) {
            string first = to_string(i);
            string second = first;
            if (digits % 2 == 1) second.pop_back(); // remove middle digit for odd-digits
            reverse(second.begin(), second.end());
            string s = first + second;
            res.push_back(stoll(s));
        }
        return res;
    }
    ll kMirror(int k, int n) {
        ll sum = 0;
        int count = 0;
        int digits = 1;
        while(count < n) {
            vector<ll> pal = generatePalindromes(digits);
            for(ll num : pal) {
                string k_base = toBaseK(num, k);
                if(isPalindrome(k_base)) {
                    sum += num;
                    count++;
                    if(count == n) return sum;
                }
            }
            digits++;
        }
        return sum;
    }
};
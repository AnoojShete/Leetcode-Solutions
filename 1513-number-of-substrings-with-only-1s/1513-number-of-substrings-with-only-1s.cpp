class Solution {
public:
    int numSub(string s) {
        int mod = 1e9 + 7;
        s.push_back('0');
        int n = s.length();
        long long count = 0;
        int ans = 0;
        for(char ch : s) {
            if(ch == '0') {
                ans = (ans + count * (count + 1) / 2) % mod;
                count = 0;
            }
            else count++;
        }
        return ans;
    }
};
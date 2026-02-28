class Solution {
public:
    int concatenatedBinary(int n) {
        long ans = 0, MOD = 1e9 + 7, bits = 0;
        for (int i = 1; i <= n; ++i) {
            if(i == 1 << bits) ++bits;
            ans = (ans << bits | i) % MOD;
        }
        return ans;
    }
};
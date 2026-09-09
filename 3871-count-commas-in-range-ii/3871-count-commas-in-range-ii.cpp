class Solution {
public:
    long long countCommas(long long n) {
        typedef long long ll;
        ll ans = 0, start = 1000, commas = 1;
        while(start <= n) {
            ll end = start * 1000 - 1;
            ll mini = min(n, end);
            ans += (mini - start + 1) * commas++;
            start = end + 1;
        }
        return ans;
    }
};
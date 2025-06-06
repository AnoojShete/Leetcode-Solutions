class Solution {
public:
    const int mod = 1e9 + 7;
    int memo[301][301];
    int solve(int num, int n, int x, int sum) {
        if(num == n+1) {
            cout << sum << " ";
            return sum == n;
        }
        if(sum > n) return 0;
        if(memo[num][sum] != -1) return memo[num][sum] % mod; 
        int count = 0;
        count += solve(num+1, n, x, sum + pow(num, x)) % mod;
        count += solve(num+1, n, x, sum) % mod;
        return memo[num][sum] = count % mod;
    }
    int numberOfWays(int n, int x) {
        memset(memo, -1, sizeof memo);
        return solve(1, n, x, 0);
    }
};
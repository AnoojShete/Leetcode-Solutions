class Solution {
public:
    int MOD = 1e9 + 7;
    vector<vector<long long>> precompute;

    int solve(vector<int> &temp) {
        if(temp.size() <= 2) return 1;
        vector<int> L, R;
        for(int i = 1; i < temp.size(); ++i) {
            int num = temp[i];
            if(num < temp.front()) L.push_back(num);
            else R.push_back(num);
        }
        long long lcount = solve(L);
        long long rcount = solve(R);

        return (precompute[L.size()+R.size()][L.size()] * lcount % MOD) * rcount % MOD;
    };

    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        precompute.resize(n + 1, vector<long long>(n + 1, 0));
        for(int i = 0; i <= n; ++i) {
            precompute[i][0] = 1;
            precompute[i][i] = 1;
            for(int j = 1; j < i; ++j) {
                precompute[i][j] = (precompute[i-1][j-1] + precompute[i-1][j]) % MOD;
            }
        }
        return solve(nums) - 1;
    }
};
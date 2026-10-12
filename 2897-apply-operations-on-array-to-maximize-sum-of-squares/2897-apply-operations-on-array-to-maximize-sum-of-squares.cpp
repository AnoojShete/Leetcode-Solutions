class Solution {
public:
    const int mod = 1e9 + 7;
    int maxSum(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        int bit[32] = {0};
        for(int i = 0; i < 32; ++i) {
            for(int num : nums) {
                if(num & (1 << i)) bit[i]++;
            }
        }
        while(k--) {
            long long temp = 0;
            for(int i = 0; i < 32; ++i) {
                if(bit[i] > 0) {
                    temp |= (1 << i);
                    bit[i]--;
                }
            }
            ans = (ans + (temp * temp) % mod) % mod; 
        }
        return ans;
    }
};
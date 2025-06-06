class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0) return false;
        int t[n+1][sum/2+1];
        for(int i = 0; i <= n; ++i) {
            for(int j = 0; j <= sum / 2; ++j) {
                if(i == 0) t[i][j] = false;
                if(j == 0) t[i][j] = true;
            }
        }
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= sum / 2; ++j) {
                if(nums[i-1] <= j) {
                    t[i][j] = t[i-1][j-nums[i-1]] || t[i-1][j];
                }
                else t[i][j] = t[i-1][j];
            }
        }
        return t[n][sum/2];
    }
};
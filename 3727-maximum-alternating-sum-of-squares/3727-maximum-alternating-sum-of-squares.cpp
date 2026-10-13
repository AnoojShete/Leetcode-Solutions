class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b) {
            a = abs(a), b = abs(b);
            return a > b;
        });
        long long pos = 0, neg = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(i < (nums.size() + 1) / 2) {
                pos += nums[i] * nums[i];
            }
            else neg += nums[i] * nums[i];
        }
        return pos - neg;
    }
};
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int AND = 0;
        int i = 0;
        int maxLen = 0;
        for(int j = 0; j < n; ++j) {
            while((AND & nums[j]) != 0) {
                AND ^= nums[i];
                i++;
            }
            AND |= nums[i];
            maxLen = max(maxLen, j - i + 1);
        }

        return maxLen;
    }
};
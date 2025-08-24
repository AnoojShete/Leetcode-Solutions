class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0;
        int length = 0;
        int countZero = 0;
        for(int j = 0; j < nums.size(); ++j) {
            if(nums[j] == 0) countZero++;
            while(countZero > 1) {
                if(nums[i++] == 0) countZero--;
            }
            length = max(length, j - i);
        }
        return length;
    }
};
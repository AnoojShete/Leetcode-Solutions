class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xor1 = 0;
        int count = 0;
        for(auto it : nums) xor1 ^= it, count += (it == 0);
        if(xor1 != 0) return nums.size();
        else if(count == nums.size()) return 0;
        return nums.size() - 1;
    }
};
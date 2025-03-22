class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xor1 = 0;
        for(int i=0; i<n; i++) {
            xor1 ^= nums[i]; 
        }
        int xor2 = 0;
        for(int i=0; i<=n; i++) {
            xor2 ^= i; 
        }
        return xor1 ^ xor2;
    }
};
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        bool mpp[1001]= {false};
        for(auto num : nums) mpp[num] = true;
        while(original < 1001 && mpp[original]) {
            original *= 2;
        }
        return original;
    }
};
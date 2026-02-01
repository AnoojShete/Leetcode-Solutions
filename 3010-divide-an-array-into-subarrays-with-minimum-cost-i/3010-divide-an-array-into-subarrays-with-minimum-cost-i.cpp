class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int mini = INT_MAX, mini2 = INT_MAX;
        for(int i = 1; i < nums.size(); ++i) {
            int num = nums[i];
            if(num < mini) {
                mini2 = mini;
                mini = num;
            } else if(num < mini2) mini2 = num;
        }
        return nums[0] + mini + mini2;
    }
};
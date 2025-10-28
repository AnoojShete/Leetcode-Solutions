class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        vector<int> rightSum, leftSum(n);
        int right = 0, left = 0;
        for(auto num : nums) {
            right += num;
            rightSum.push_back(right);
        }
        leftSum[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; --i) {
            leftSum[i] += leftSum[i+1];
        }
        for(int i = 0; i < n; ++i) {
            if(nums[i] == 0 && rightSum[i] == leftSum[i]) return rightSum[i]-1;
        }
        return 0;
    }
};

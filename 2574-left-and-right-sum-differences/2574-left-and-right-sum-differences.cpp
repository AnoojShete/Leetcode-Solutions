class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        int rightSum = accumulate(nums.begin(), nums.end(), 0);
        vector<int> ans;
        int leftSum = 0;
        for(auto num : nums) {
            rightSum -= num;
            ans.push_back(abs(leftSum - rightSum));
            leftSum += num;
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int left = 0, right = n - 1;
        for(int k = n - 1; k >= 0; --k) {
            if(abs(nums[right]) > abs(nums[left])) {
                ans[k] = nums[right] * nums[right];
                right--;
            }
            else { 
                ans[k] = nums[left] * nums[left];
                left++;
            }
        }

        return ans;
    }
};
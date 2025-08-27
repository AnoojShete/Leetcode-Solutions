class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int count = 0;
        for(int i = n - 1; i >= 0; --i) {
            int j = i - 1, k = 0;
            while(k < j) {
                int sum = nums[j] + nums[k];
                if(sum > nums[i]) {
                    count += j - k;
                    j--;
                }
                else k++;
            }
        }
        return count;
    }
};
class Solution {
public:
    bool isPossible(vector<int>& nums, int k, int mid) {
        int n = nums.size();
        int sum = 0;
        int splits = 1;
        for(int i = 0; i < n; i++) {
            if(sum + nums[i] > mid) {
                splits++;
                sum = nums[i];
            }
            else {
                sum += nums[i];
            }
        }
        if(splits > k) return true;  
        return false;
    }
    int splitArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int low = nums[n - 1];
        int high = accumulate(nums.begin(), nums.end(), 0);

        while(low <= high) {
            int mid = (low + high) / 2;
            if(isPossible(nums, k, mid)) low = mid + 1;
            else high = mid - 1;
        }

        return low;
    }
};
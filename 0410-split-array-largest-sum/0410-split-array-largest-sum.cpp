class Solution {
public:
    int calculatePartitions(vector<int>& nums, int mid) {
        int n = nums.size();
        long long sum = 0;
        int partitions = 1;
        for(int i = 0; i < n; i++) {
            if(sum + nums[i] <= mid) {
                sum += nums[i];
            }
            else {
                partitions++;
                sum = nums[i];
            }
        }
        return partitions;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while(low <= high) {
            int mid = (low + high) / 2;
            if(calculatePartitions(nums, mid) > k) low = mid + 1;
            else high = mid - 1;
        }

        return low;
    }
};
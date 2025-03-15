class Solution {
public:
    bool isPossible(vector<int> &nums, int k, int mid) {
        int n = nums.size();
        int i = 0;
        while(i < n) {
            if(nums[i] <= mid) {
                i += 2;
                k--;
            }
            else i++;
        }

        return k == 0;
    }
    int minCapability(vector<int>& nums, int k) {
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());

        int ans = -1;
        while(low <= high) {
            int mid = (low + high) / 2;

            if(isPossible(nums, k, mid)) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }

        return ans;
    }
};
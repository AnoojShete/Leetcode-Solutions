typedef vector<int> vi;

class Solution {
public:
    bool solve(vi &nums, int k, int mid) {
        int count = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] <= mid) {
                count++;
                i++;
            }
        }
        return count < k;
    }

    int minCapability(vector<int>& nums, int k) {
        int low = 0;
        int high = *max_element(nums.begin(), nums.end());

        while(low < high) {
            int mid = (low + high) / 2;
            if(solve(nums, k, mid)) {
                low = mid + 1;
            }
            else high = mid;
        }

        return low;
    }
};
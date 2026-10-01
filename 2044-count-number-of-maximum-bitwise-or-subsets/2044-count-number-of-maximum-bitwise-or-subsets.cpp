class Solution {
public:
    int maxi = 0, count = 0;
    void solve(int idx, vector<int> &nums, int temp) {
        if(idx == nums.size()) {
            if(maxi < temp) {
                maxi = temp;
                count = 1;
            }
            else if(maxi == temp) {
                count++;
            }
            cout << temp << " ";
            return;
        }
        solve(idx + 1, nums, temp | nums[idx]);
        solve(idx + 1, nums, temp);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        solve(0, nums, 0);
        return count;
    }
};
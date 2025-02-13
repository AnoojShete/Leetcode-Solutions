class Solution {
public:
    int ans = 0;
    bool isValid(int a, int b) {
        int temp = sqrt(a + b);
        return (temp * temp == a + b);
    }
    void solve(vector<int> nums, int index) {
        if(index >= nums.size()) {
            ans++;
            return;
        }
        for(int i = index; i < nums.size(); ++i) {
            if(i > index && nums[i] == nums[index]) continue;
            swap(nums[i], nums[index]);
            if(index == 0 || (index > 0 && isValid(nums[index - 1], nums[index]))) {
                solve(nums, index + 1);
                swap(nums[i], nums[index]);
            }
        }
    }
    int numSquarefulPerms(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        solve(nums, 0);
        return ans;
    }
};
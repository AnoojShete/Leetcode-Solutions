class Solution {
public:
    void solve(int index, vector<int> &nums, int temp, int &sum) {
        if(index == nums.size()) {
            sum += temp;
            return;
        }
        
        int temp1 = temp ^ nums[index];
        solve(index + 1, nums, temp1, sum);
        int temp2 = temp;
        solve(index + 1, nums, temp2, sum);
    }
    int subsetXORSum(vector<int>& nums) {
        int sum = 0;
        solve(0, nums, 0, sum);

        return sum;
    }
};
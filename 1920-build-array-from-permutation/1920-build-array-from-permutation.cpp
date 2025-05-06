class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n);
        for(auto it : nums) {
            v[it] = nums[nums[it]];
        }

        return v;
    }
};
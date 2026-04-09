class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n+1, 0);
        for(auto &query : queries) {
            int l = query[0], r = query[1];
            diff[l]++;
            diff[r+1]--;
        }
        int count = 0;
        for(int i = 0; i < n; ++i) {
            count += diff[i];
            if(nums[i] > count) return false;
        }
        return true;
    }
};
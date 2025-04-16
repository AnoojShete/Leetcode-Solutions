class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        int n = nums.size();
        long long count = 0;
        for(int l = 0, r = 0; r < n; ++r) {
            k -= mpp[nums[r]]++;
            while (k <= 0) {
                k += --mpp[nums[l++]];
            }
            count += l;
        }
        return count;
    }
};
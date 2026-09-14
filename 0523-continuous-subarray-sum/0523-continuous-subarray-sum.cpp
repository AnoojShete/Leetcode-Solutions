class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum = 0;
        unordered_map<int, int> mpp;
        mpp[0] = -1;
        for(int i = 0; i < n; ++i) {
            sum += nums[i];
            int mod = sum % k;
            if(mpp.find(mod) != mpp.end()) {
                if(i - mpp[mod] >= 2) return true;
            }
            else mpp[mod] = i;
        }
        return false;
    }
};
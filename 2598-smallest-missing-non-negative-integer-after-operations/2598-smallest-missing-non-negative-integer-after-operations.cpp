class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, int> mpp;
        int maxi = 0;
        for(auto num : nums) {
            int mod = ((num % value) + value) % value;
            if(mpp.find(mod) != mpp.end()) {
                mpp[mod + mpp[mod] * value]++;
                mpp[mod]++;
                maxi = max(maxi, mod + mpp[mod]*value);
            }
            else mpp[mod]++, maxi = max(maxi, mod);
        }
        for(int i = 0; i <= maxi; ++i) {
            if(mpp.find(i) == mpp.end()) return i;
        }
        return maxi+1;
    }
};
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxi = 0;
        long long maxDiff = 0;
        long long ans = 0;
        int n = nums.size();
        for(long long num : nums) {
            ans = max(ans, maxi * maxDiff);
            maxDiff = max(maxDiff, maxi - num);
            maxi = max(maxi, num);
        }

        return ans;
    }
};
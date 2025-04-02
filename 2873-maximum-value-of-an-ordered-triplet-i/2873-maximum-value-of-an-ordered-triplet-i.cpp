class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxi = 0, maxDiff = 0, ans = 0;
        for(long long num : nums) {
            ans = max(ans, maxDiff * num);
            maxDiff = max(maxDiff, maxi - num);
            maxi = max(maxi, num);
        }

        return ans;
    }
};
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxi = 0, maxDiff = 0, ans = 0;
        for(long long num : nums) {
            maxi = max(maxi, num);
            maxDiff = max(maxDiff, maxi - num);
            ans = max(ans, maxDiff * num);
        }

        return ans;
    }
};
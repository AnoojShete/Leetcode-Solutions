class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        #define all(a) a.begin(), a.end()
        return 1LL * k * (*max_element(all(nums)) - *min_element(all(nums)));
    }
};
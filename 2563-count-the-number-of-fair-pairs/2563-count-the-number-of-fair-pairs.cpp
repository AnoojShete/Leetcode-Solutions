typedef long long ll;

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        ll count = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                int sum = nums[i] + nums[j];
                if(sum >= lower && sum <= upper) count++;
            }
        }
        return count;
    }
};
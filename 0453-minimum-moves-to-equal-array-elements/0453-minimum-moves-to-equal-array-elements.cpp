class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mini = *min_element(nums.begin(), nums.end());
        int count = 0;
        for(auto num : nums) count += (num - mini);
        return count;
    }
};